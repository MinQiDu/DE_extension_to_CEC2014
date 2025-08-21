#ifndef SHADE_H
#define SHADE_H
//#include "benchmark.h"
#include "cec14_test_func.h" /* 包含 CEC14 函數的宣告 */ 
#include <random>			 /* for random device & mt19937 */
using namespace std;

class algo_SHADE
{
public:
	algo_SHADE();       /* constructor 宣告 */
	void RunALG(int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool archive_flag);
private:
	random_device rd;  /*宣告亂數引擎*/
	mt19937 gen;

	bool archive_flag; /* 是否使用 archive list A */
	int func_id; /* benchmark function id */
	int iter_c;  /* 當前迭代次數 */
	int dim;
	int pop_size;
	int mnfes;
	int nfes;
	//double mCR;        /* adaptive parameter 1 (cross_rate) */
	//double mF;         /* adaptive parameter 2 (= F, donor_rate) */
	vector<double> CR; /* 存此代每個個體的 CR */
	vector<double> F;  /* 存此代每個個體的 F */
	//double c;          /* adaptation rate */
	double p;          /* top % pop chosen by pbest */
	vector<double> MCR; /* 存跨越世代的成功mCR */
	vector<double> MF;  /* 存跨越世代的成功mF */
	int H; /* MCR & MF 大小 */
	int k; /* 要被自適應更新 MCR & MF 的 index */

	vector<double> sCR;                 /* 存此代中成功更新的個體的CR */
	vector<double> sF;                  /* 存此代中成功更新的個體的F */
	vector<double> delta_fit; 		    /* 存此代中成功更新的個體的 fitness 差值 */
	vector<vector<double>> A;           /* 存歷代中被淘汰掉的原解，size = pop_size */
	vector<vector<double>> pop;         /* dim*pop_size 個群體解 */
	vector<vector<double>> donor_pop;   /* 變異後的 donor 解 */
	vector<vector<double>> current_pop; /* crossover 後的新解 */
	vector<double> fit;                 /* 原解的 fitness */
	vector<double> current_fit;         /* 新解的 fitness */
	double best_fit;                    /* 紀錄最佳fitness */
	vector<double> best_sol;            /* 紀錄最佳解 */

	double lower_bound, upper_bound;    /* 不同函數對應的上下界 */

	vector<vector<double>> eva_fit_record;  /* 輸出每一 evaluation fitness 收斂結果用 */
	int current_run;						/* 當前運行 run 數 */

	void Init();           /* 產生初始dim*pop_size個群體解 */
	void Mutation();       /* 產生donor解 */
	void Crossover();      /* 原解 & donor解 交叉生成recent解 */
	void Evaluation();     /* 計算recent解的 fitness */
	void Determination();  /* update誰(原解 or recent解)可成為下一代解
						   ，update best_fit */
	void ParaAdaptation(); /* 更新 mCR & mF */

};

#endif
