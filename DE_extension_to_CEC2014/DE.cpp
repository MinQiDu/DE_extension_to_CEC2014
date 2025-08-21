#include "DE.h"
#include <ctime>
#include <cstdlib>
#include <algorithm> /* for auto */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>     /* for sqrt */
#include <numeric>   /* for accumulate */
#include "DE_fileoutput.h" // �]�t FileOutput �禡���ŧi

/* Constructor ��l�ƶüƤ��� */
algo_DE::algo_DE()
	: gen(rd()) /* �� rd ��l�� gen�]�O��o�u���b��l�ƦC���^ */
{
}

void algo_DE::RunALG(int _dim, int _pop_size, double _CR, double _F, int _func_id)
{
	int run = 51; // �]�w�B�榸��
	vector<double> best_fit_record; // �Ω�O���C���B�檺�̨� fitness
	best_fit_record.reserve(run);
	//iter_fit_record.resize(run);
	eva_fit_record.resize(run); // �Ω�O���C���B�檺 evaluation fitness

	for (int r = 0; r < run; ++r)
	{
		iter_c = 0; // ��e���N����
		dim = _dim;
		int r_init_pop = 18; // ��l�s��j�p���
		pop_size = dim * r_init_pop;
		CR = _CR;
		F = _F;
		func_id = _func_id;

		Init();					 // ��l�Ƹs���

		nfes = 0;				 // ��l�Ƶ�������
		mnfes = dim * 10000;	 // �̤j��������

		//iter_fit_record[r].reserve(iter); // ���C���B�檺 fitness �������t�Ŷ�
		eva_fit_record[r].reserve(mnfes);   // ���C���B�檺 evaluation fitness �������t�Ŷ�
		current_run = r;					// �O����e�B�榸�ơA�� Determination() �����ϥ�

		while (nfes < mnfes)
		{
			Mutation(); // ����donor��
			Crossover(); // ��e�ͦ�current��
			Evaluation(); // �p��current�Ѫ�fitness
			Determination(); // ��s�U�@�N��

			//iter_fit_record[r].push_back(best_fit); // ������e���N���̨� fitness
		}
		best_fit_record.push_back(best_fit); // �O���Ҧ� run �B�檺�̨� fitness
		/*cout << "best fitness in run " << (r + 1) << ": " << best_fit << endl;
		cout << "best solution found in run " << (r + 1) << ": ";
		for (const auto& val : best_sol) {
			cout << val << " ";
		}
		cout << endl;*/
	}
	// ��� eva_fit_record 
	/*std::cout << eva_fit_record[current_run].size() << " evaluations recorded for run " << current_run + 1 << std::endl;
	for (const auto& fit : eva_fit_record[current_run]) {
		std::cout << fit << " ";
	}*/
	// ��X���G
	double avg_best_fit = accumulate(best_fit_record.begin(), best_fit_record.end(), 0.0) / run;
	std::cout << "Avg Best fitness: " << avg_best_fit << endl;
	// ��X���ɮ�
	DE_FileOutput(
		run,
		best_fit_record,
		eva_fit_record,
		func_id,
		dim,
		pop_size,
		CR,
		F,
		avg_best_fit
	);
}

void algo_DE::Init()
{
	// ��l�Ƹs���
	//Benchmark benchmark(func_id);
	//benchmark.GetBounds(lower_bound, upper_bound);
	GetBounds(lower_bound, upper_bound, func_id);
	//cout << "Lower bound: " << lower_bound << ", Upper bound: " << upper_bound << endl;

	uniform_real_distribution<double> dist_init(lower_bound, upper_bound); /* �ϥαq��Ǩ���������� */

	pop.clear();
	current_pop.clear();
	fit.clear();
	current_fit.clear();

	pop.assign(pop_size, vector<double>(dim)); // ��l��pop
	current_pop.assign(pop_size, vector<double>(dim)); // ��l��current_pop
	fit.assign(pop_size, 0.0); // ��l�� fit
	current_fit.assign(pop_size, 0.0); // ��l�� current_fit

	// ���ͪ�l��pop
	for (int i = 0; i < pop_size; ++i) {
		for (int j = 0; j < dim; ++j) {
			pop[i][j] = dist_init(gen);
			//cout << pop[i][j] << " "; // �L�X��l��
		}
	}
	// ��l��donor_pop�Mcurrent_pop
	donor_pop = pop;
	current_pop = pop;

	// �p���l�Ѫ�fitness
	for (int i = 0; i < pop_size; ++i) {
		//fit[i] = benchmark.Evaluate(pop[i]);
		cec14_test_func(pop[i].data(), &fit[i], dim, 1, func_id);

		if (i == 0 || fit[i] < best_fit) {
			// ��s�̨θ�
			best_fit = fit[i];
			best_sol = pop[i];
		}
	}
}

/* ����donor�� */
void algo_DE::Mutation()
{
	uniform_int_distribution<int> dist_idx(0, pop_size - 1);

	for (int i = 0; i < pop_size; ++i)
	{
		int r1, r2, r3;

		do { r1 = dist_idx(gen); } while (r1 == i);
		do { r2 = dist_idx(gen); } while (r2 == i || r2 == r1);
		do { r3 = dist_idx(gen); } while (r3 == i || r3 == r2 || r3 == r1);

		for (int j = 0; j < dim; ++j)
		{
			donor_pop[i][j] = pop[r1][j]
				+ F * (pop[r2][j] - pop[r3][j]);
		}
	}
}

/* ��ѩMdonor�ѥ�e����current�� */
void algo_DE::Crossover()
{
	uniform_int_distribution<int> dist_idx(0, dim - 1);
	uniform_real_distribution<double> dist_real(0.0, 1.0);

	for (int i = 0; i < pop_size; ++i)
	{
		int jrand = dist_idx(gen);     /* �O�ҥ����ܤ֤@��idx���ܲ� */

		for (int j = 0; j < dim; ++j)
		{
			double r = dist_real(gen);

			if (r < CR || jrand == j) /* ���H��[0, 1]�B�I�Ƥp��cross_rate�άO�H��idx�����eidx */
			{
				current_pop[i][j] = donor_pop[i][j]; /* �N�ܲ����s�� */
			}
			else
			{
				current_pop[i][j] = pop[i][j];       /* �_�h������� */
			}
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

void algo_DE::Evaluation()
{
	// �p��current�Ѫ�fitness
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

/* ����s��fitness,update population & fit�Aupdate best_sol & best_fit */
void algo_DE::Determination()
{
	for (int i = 0; i < pop_size; ++i)
	{
		if (current_fit[i] < fit[i])       /* ��current���u���ѡA��s */
		{
			fit[i] = current_fit[i];
			pop[i] = current_pop[i];

			if (current_fit[i] < best_fit) /* ��current���u��̨θѡA��s */
			{
				best_fit = current_fit[i];
				best_sol = current_pop[i];
			}
		}
		eva_fit_record[current_run].push_back(best_fit); // �O���C��evaluation time���̨θ�
	}
}
	//cout << "sF size: " << sF.size() << ", sCR size: " << sCR.size() << endl;

	// Elitism: �O�d�̦n����
	// If the worst fitness in the population is better than the best fitness ever found,
	// replace the corresponding individual with the best solution found.
	/*auto worst_it = std::max_element(fit.begin(), fit.end());
	if (worst_it != fit.end() && best_fit < *worst_it) {
		int idx = std::distance(fit.begin(), worst_it);
		pop[idx] = best_sol;
		fit[idx] = best_fit;
	}*/