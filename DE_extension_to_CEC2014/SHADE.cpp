#include "SHADE.h"
#include <ctime>
#include <cstdlib>
#include <algorithm> /* for auto */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>     /* for sqrt */
#include <numeric>   /* for accumulate */
#include "SHADE_fileoutput.h" // 包含 FileOutput 函式的宣告

/* Constructor 初始化亂數引擎 */
algo_SHADE::algo_SHADE()
	: gen(rd()) /* 用 rd 初始化 gen（記住這只能放在初始化列表中） */
{
}

void algo_SHADE::RunALG(int _dim, int _pop_size, double _mCR, double _mF, double _H, double _p, int _func_id, bool _archive_flag)
{
	int run = 51; // 設定運行次數
	vector<double> best_fit_record; // 用於記錄每次運行的最佳 fitness
	best_fit_record.reserve(run);
	//iter_fit_record.resize(run);
	eva_fit_record.resize(run); // 用於記錄每次運行的 evaluation fitness

	for (int r = 0; r < run; ++r)
	{
		iter_c = 0;
		dim = _dim;
		int r_init_pop = 18; // 初始群體大小比例
		pop_size = dim * r_init_pop;
		H = _H;
		p = _p;
		func_id = _func_id;
		archive_flag = _archive_flag;

		Init(); // 初始化群體解

		nfes = 0; // 初始化評估次數
		mnfes = dim * 10000; // 最大評估次數

		eva_fit_record[r].reserve(mnfes);   // 為每次運行的 evaluation fitness 紀錄分配空間	
		current_run = r;					// 記錄當前運行次數，供 Determination() 紀錄使用

		while (nfes < mnfes)
		{
			Mutation(); // 產生donor解
			Crossover(); // 交叉生成current解
			Evaluation(); // 計算current解的fitness
			Determination(); // 更新下一代解
			ParaAdaptation(); // 更新mCR & mF
		}
		best_fit_record.push_back(best_fit); // 記錄所有 run 運行的最佳 fitness
		/*cout << "best fitness in run " << (r + 1) << ": " << best_fit << endl;
		cout << "best solution found in run " << (r + 1) << ": ";
		for (const auto& val : best_sol) {
			cout << val << " ";
		}
		cout << endl;*/
	}

	// 輸出結果
	double avg_best_fit = accumulate(best_fit_record.begin(), best_fit_record.end(), 0.0) / run;
	std::cout << "Avg Best fitness: " << avg_best_fit << endl;
	// 輸出到檔案
	SHADE_FileOutput(
		run,
		best_fit_record,
		eva_fit_record,
		func_id,
		dim,
		pop_size,
		_mCR,
		_mF,
		H,
		p,
		archive_flag,
		avg_best_fit
	);
}

void algo_SHADE::Init()
{
	// 初始化 best_fit 和 best_sol
	best_fit = numeric_limits<double>::infinity();
	best_sol.clear();

	// 初始化群體解
	//Benchmark benchmark(func_id);
	//benchmark.GetBounds(lower_bound, upper_bound);
	GetBounds(lower_bound, upper_bound, func_id);
	//cout << "Lower bound: " << lower_bound << ", Upper bound: " << upper_bound << endl;

	uniform_real_distribution<double> dist_init(lower_bound, upper_bound); /* 使用從基準函數獲取的邊界 */

	pop.clear();
	current_pop.clear();
	fit.clear();
	current_fit.clear();
	A.clear();   // A 存過去被淘汰的個體，初始為空
	A.reserve(pop_size); // Reserve space for A

	pop.assign(pop_size, vector<double>(dim)); // 初始化pop
	current_pop.assign(pop_size, vector<double>(dim)); // 初始化current_pop
	fit.assign(pop_size, 0.0); // 初始化 fit
	current_fit.assign(pop_size, 0.0); // 初始化 current_fit

	MCR.assign(H, 0.5); // 初始化 MCR
	MF.assign(H, 0.5);  // 初始化 MF
	CR.assign(pop_size, 0.5); // 初始化 CR
	F.assign(pop_size, 0.5);   // 初始化 F

	k = 0; // 初始化 k

	// 產生初始解pop
	for (int i = 0; i < pop_size; ++i) {
		for (int j = 0; j < dim; ++j) {
			pop[i][j] = dist_init(gen);
			//cout << pop[i][j] << " "; // 印出初始解
		}
	}
	// 初始化donor_pop和current_pop
	donor_pop = pop;
	current_pop = pop;

	// 計算初始解的fitness
	for (int i = 0; i < pop_size; ++i) {
		//fit[i] = benchmark.Evaluate(pop[i]);
		cec14_test_func(pop[i].data(), &fit[i], dim, 1, func_id);

		if (i == 0 || fit[i] < best_fit) {
			// 更新最佳解
			best_fit = fit[i];
			best_sol = pop[i];
		}
	}
}

void algo_SHADE::Mutation()
{
	// 產生donor解
	donor_pop.clear();
	donor_pop.resize(pop_size, vector<double>(dim));

	uniform_int_distribution<int> dist_r(0, H - 1); /* 整數均勻分布 for 生成 r */
	/* ---- x_pbest ---- */
	double p_min = 2.0 / static_cast<double>(pop_size);
	double p_i;  // sampled p for this individual

	if (p_min < 0.2) {
		std::uniform_real_distribution<double> dist_p(p_min, 0.2);
		p_i = dist_p(gen);
	}
	else {
		// NP < 10 時：至少要能選到 2 個 → 令 p_i = p_min
		p_i = p_min;
	}

	vector<vector<double>> pop_A = pop;                         /* 先複製pop */
	pop_A.insert(pop_A.end(), A.begin(), A.end());              /* 再接上A */

	for (int i = 0; i < pop_size; ++i)
	{
		int r = dist_r(gen); /* 生成 r */
		normal_distribution<double> dist_CR(MCR[r], 0.1); /* 常態分布 for 生成個體的 CR */
		cauchy_distribution<double> dist_F(MF[r], 0.1);   /* 柯西分布 for 生成個體的 F */

		/* 生成此代所有個體的 CR[i] & F[i] */
		CR[i] = max(0.0, min(1.0, dist_CR(gen))); // truncate, 確保 CR[i] 在 [0, 1] 範圍內

		do {
			F[i] = dist_F(gen);
		} while (F[i] <= 0.0 || F[i] > 1.0);       /* truncate */
		//F[i] = max(F[i], 0.1); // Clamp F to at least 0.1

		/* 選出x_pbest, x_r1, x_r2 來產生 donor_pop */
		/* x_pbest */
		// p_num = ceil(p_i * NP)，至少 2
		int p_num = max(2, static_cast<int>(std::ceil(p_i * pop_size)));
		if (p_num < 2) p_num = 2;                                   /* 確保至少有2個候選個體 */
		vector<pair<double, int>> fit_idx(pop_size);                /* pair = { fitness, index } */
		for (int i = 0; i < pop_size; ++i)                          /* 建立 fit_idx 以供排序列出個體 fitness 排名 */
		{
			fit_idx[i] = { fit[i], i };
		}
		sort(fit_idx.begin(), fit_idx.end());                       /* fitness 由小->大 */

		int idx_pbest;
		do {
			uniform_int_distribution<int> dist_pbest(0, p_num - 1); /* 整數均勻分布 for 生成index */
			idx_pbest = fit_idx[dist_pbest(gen)].second;            /* pbest 在 pop 中的 index */
		} while (idx_pbest == i);                                   /* 確保idx_pbest跟當前個體i不同 */
		vector<double> x_pbest = pop[idx_pbest];                    /* 得到 x_pbest */

		/* x_r1 */
		uniform_int_distribution<int> dist_r1(0, pop_size - 1);
		int idx_r1;
		do {
			idx_r1 = dist_r1(gen);
		} while (idx_r1 == i || idx_r1 == idx_pbest);
		vector<double> x_r1 = pop[idx_r1];                          /* 得到 x_r1 */

		/* x_r2 */
		uniform_int_distribution<int> dist_r2(0, pop_size + A.size() - 1);

		int idx_r2;
		do {
			idx_r2 = dist_r2(gen);
		} while (idx_r2 == i || idx_r2 == idx_pbest || idx_r2 == idx_r1);
		vector<double> x_r2 = pop_A[idx_r2];                        /* 得到 x_r2 */

		for (int j = 0; j < dim; ++j)                               /* 算出此個體的 donor 解 */
		{
			donor_pop[i][j] = pop[i][j] + F[i] * (x_pbest[j] - pop[i][j]) + F[i] * (x_r1[j] - x_r2[j]);

			// reflective boundary condition
			if (donor_pop[i][j] < lower_bound) {
				donor_pop[i][j] = lower_bound + (lower_bound - donor_pop[i][j]);
				if (donor_pop[i][j] > upper_bound) donor_pop[i][j] = lower_bound;
			}
			if (donor_pop[i][j] > upper_bound) {
				donor_pop[i][j] = upper_bound - (donor_pop[i][j] - upper_bound);
				if (donor_pop[i][j] < lower_bound) donor_pop[i][j] = upper_bound;
			}
		}
	}
}

void algo_SHADE::Crossover()
{
	// 交叉生成recent解
	current_pop.clear();
	current_pop.resize(pop_size, vector<double>(dim));

	uniform_int_distribution<int> dist_idx(0, dim - 1);  // 整數均勻分布 for 隨機維度選擇
	uniform_real_distribution<double> dist_CR(0.0, 1.0); // 均勻分布 for r
	for (int i = 0; i < pop_size; ++i)
	{
		int j_rand = dist_idx(gen); // 隨機選擇一個維度進行確保至少有一個維度來自donor解
		for (int j = 0; j < dim; ++j)
		{
			double r = dist_CR(gen); // 生成隨機數 r
			if (j == j_rand || r < CR[i]) // 確保至少有一個維度來自donor解
				current_pop[i][j] = donor_pop[i][j]; // 如果是隨機選中的維度或r小於CR[i]，則從donor解中取值
			else
				current_pop[i][j] = pop[i][j]; // 否則從原解中取值

			// reflective boundary condition
			if (current_pop[i][j] < lower_bound) {
				current_pop[i][j] = lower_bound + (lower_bound - current_pop[i][j]);
				if (current_pop[i][j] > upper_bound) current_pop[i][j] = lower_bound;
			}
			else if (current_pop[i][j] > upper_bound) {
				current_pop[i][j] = upper_bound - (current_pop[i][j] - upper_bound);
				if (current_pop[i][j] < lower_bound) current_pop[i][j] = upper_bound;
			}

			//// jitter
			//if (fabs(donor_pop[i][j] - lower_bound) < 1e-8 || fabs(donor_pop[i][j] - upper_bound) < 1e-8) {
			//	donor_pop[i][j] += (upper_bound - lower_bound) * 0.01 * (2.0 * dist_CR(gen) - 1.0); // small random step
			//}
		}
	}
}

void algo_SHADE::Evaluation()
{
	// 計算current解的fitness
	current_fit.clear();
	current_fit.resize(pop_size, 0.0);
	//Benchmark benchmark(func_id);
	for (int i = 0; i < pop_size; ++i)
	{
		//current_fit[i] = benchmark.Evaluate(current_pop[i]);
		cec14_test_func(current_pop[i].data(), &current_fit[i], dim, 1, func_id);
		nfes++;
	}
}

void algo_SHADE::Determination()
{
	sF.reserve(pop_size);
	sCR.reserve(pop_size);
	// 更新下一代解
	for (int i = 0; i < pop_size; ++i)
	{
		if (current_fit[i] < fit[i]) // 如果current解的fitness更好
		{
			if (archive_flag)
			{
				A.push_back(pop[i]); // 將淘汰掉的原解加入A
			}
			pop[i] = current_pop[i]; // 更新pop[i]為current解

			// Record fitness improvement for weighting
			delta_fit.push_back(fit[i] - current_fit[i]); // positive value for 求最小問題

			fit[i] = current_fit[i]; // 更新fitness
			sF.push_back(F[i]);		 // 將成功更新的F加入sF
			sCR.push_back(CR[i]);	 // 將成功更新的CR加入sCR
			if (fit[i] < best_fit)   // 如果更新後的fitness更好，更新best_fit和best_sol
			{
				best_fit = fit[i];
				best_sol = pop[i];
			}
		}
		eva_fit_record[current_run].push_back(best_fit); // 記錄每次evaluation time的最佳解
	}
	//cout << "sF size: " << sF.size() << ", sCR size: " << sCR.size() << endl;

	// Elitism: 保留最好的解
	// If the worst fitness in the population is better than the best fitness ever found,
	// replace the corresponding individual with the best solution found.
	/*auto worst_it = std::max_element(fit.begin(), fit.end());
	if (worst_it != fit.end() && best_fit < *worst_it) {
		int idx = std::distance(fit.begin(), worst_it);
		pop[idx] = best_sol;
		fit[idx] = best_fit;
	}*/
}

void algo_SHADE::ParaAdaptation()
{
	// Maintain size of A <= pop_size
	while (A.size() > pop_size)
	{
		uniform_int_distribution<int> dist_idx(0, A.size() - 1);
		int idx = dist_idx(gen);
		A.erase(A.begin() + idx);
	}

	// MCR adaptation (arithmetic mean)
	double mean_sCR = MCR[k];
	if (!sCR.empty()) {
		// 如果 sCR 不為空，才更新
		double sum_sCR = 0.0;
		double sum_delta_fit = 0.0;
		for (int i = 0; i < sCR.size(); ++i) {
			sum_sCR += delta_fit[i] * sCR[i];
			sum_delta_fit += delta_fit[i]; // accumulate fitness improvements
		}
		mean_sCR = sum_sCR / sum_delta_fit;
	}
	MCR[k] = mean_sCR; // Update MCR for the current generation

	// MF adaptation (weighted Lehmer mean)
	double mean_sF = MF[k];
	if (!sF.empty()) {
		// 如果 sF 不為空，才更新
		double numerator = 0.0;
		double denominator = 0.0;
		for (size_t i = 0; i < sF.size(); ++i) {
			if (sF[i] > 0.0) { // filter out non-positive F
				numerator += delta_fit[i] * sF[i] * sF[i];
				denominator += delta_fit[i] * sF[i];
			}
		}
		if (denominator > 1e-12) // avoid division by zero
			mean_sF = numerator / denominator;
	}
	MF[k] = mean_sF; // Update MF for the current generation

	k = (k + 1) % H; // Update k for the next generation
	sCR.clear();
	sF.clear();
	delta_fit.clear();
	// Update ParaAdaptation strategy:
	// Weighted Lehmer Mean: mean_sF now uses fitness improvement (delta_fit) as weights, as per the JADE paper.
	// Filter F : Only positive F values are used.
	// Numerical Stability : Added a small epsilon to avoid division by zero.
	// delta_fit : You need to record the fitness improvement for each successful individual in Determination :
}