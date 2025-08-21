#ifndef DE_H
#define DE_H
//#include "benchmark.h"
#include "cec14_test_func.h" /* �]�t CEC14 ��ƪ��ŧi */ 
#include <random>			 /* for random device & mt19937 */
using namespace std;

class algo_DE
{
public:
	algo_DE();       /* constructor �ŧi */
	void RunALG(int dim, int pop_size, double CR, double F, int func_id);
private:
	random_device rd;  /*�ŧi�üƤ���*/
	mt19937 gen;

	int func_id; /* benchmark function id */
	int iter_c;  /* ��e���N���� */
	int dim;
	int pop_size;
	int mnfes;
	int nfes;
	double CR;        /* parameter 1 (cross_rate) */
	double F;         /* parameter 2 (= F, donor_rate) */

	vector<vector<double>> pop;         /* dim*pop_size �Ӹs��� */
	vector<vector<double>> donor_pop;   /* �ܲ��᪺ donor �� */
	vector<vector<double>> current_pop; /* crossover �᪺�s�� */
	vector<double> fit;                 /* ��Ѫ� fitness */
	vector<double> current_fit;         /* �s�Ѫ� fitness */
	double best_fit;                    /* �����̨�fitness */
	vector<double> best_sol;            /* �����̨θ� */

	double lower_bound, upper_bound;    /* ���P��ƹ������W�U�� */

	vector<vector<double>> eva_fit_record; /* ��X�C�@ run �C��evaluation fitness ���ĵ��G�� */
	int current_run;					   /* ��e�B�� run �� */

	void Init();           /* ���ͪ�ldim*pop_size�Ӹs��� */
	void Mutation();       /* ����donor�� */
	void Crossover();      /* ��� & donor�� ��e�ͦ�recent�� */
	void Evaluation();     /* �p��recent�Ѫ� fitness */
	void Determination();  /* update��(��� or recent��)�i�����U�@�N�ѡAupdate best_fit */
};

#endif
