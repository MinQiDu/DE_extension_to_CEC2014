#ifndef LSHADE_H
#define LSHADE_H
//#include "benchmark.h"
#include "org_cec14_test_func.h" /* �]�t CEC14 ��ƪ��ŧi */ 
#include <random>			 /* for random device & mt19937 */
using namespace std;

class algo_LSHADE
{
public:
	algo_LSHADE();     /* constructor �ŧi */
	void RunALG(int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool archive_flag);
private:
	random_device rd;  /*�ŧi�üƤ���*/
	mt19937 gen;

	bool archive_flag; /* �O�_�ϥ� archive list A */
	int func_id;	   /* benchmark function id */
	int iter_c;		   /* ��e���N���� */
	int dim;

	int init_pop_size;		/* ��l�s��j�p */
	int pop_size;			/* ��e�s��j�p */
	int min_pop_size;		/* �̤p�s��j�p = 4 */
	int max_archive_size;	/* archive list A ���̤j�j�p */

	int mnfes;
	int nfes;
	//double mCR;      /* adaptive parameter 1 (cross_rate) */
	//double mF;       /* adaptive parameter 2 (= F, donor_rate) */
	vector<double> CR; /* �s���N�C�ӭ��骺 CR */
	vector<double> F;  /* �s���N�C�ӭ��骺 F */
	//double c;        /* adaptation rate */
	double p;          /* top % pop chosen by pbest */
	vector<double> MCR;/* �s��V�@�N�����\mCR */
	vector<double> MF; /* �s��V�@�N�����\mF */
	int H;			   /* MCR & MF �j�p */
	int k;			   /* �n�Q�۾A����s MCR & MF �� index */

	double r_init_pop; /* ��l�s��j�p����� */
	double r_archive;  /* archive list A ����� */

	vector<double> sCR;                 /* �s���N�����\��s�����骺CR */
	vector<double> sF;                  /* �s���N�����\��s�����骺F */
	vector<double> delta_fit; 		    /* �s���N�����\��s�����骺 fitness �t�� */
	vector<vector<double>> A;           /* �s���N���Q�^�O������ѡAsize = pop_size */
	vector<vector<double>> pop;         /* dim*pop_size �Ӹs��� */
	vector<vector<double>> donor_pop;   /* �ܲ��᪺ donor �� */
	vector<vector<double>> current_pop; /* crossover �᪺�s�� */
	vector<double> fit;                 /* ��Ѫ� fitness */
	vector<double> current_fit;         /* �s�Ѫ� fitness */
	double best_fit;                    /* �����̨�fitness */
	vector<double> best_sol;            /* �����̨θ� */

	double lower_bound, upper_bound;    /* ���P��ƹ������W�U�� */

	vector<vector<double>> eva_fit_record;		/* ��X�C�@ evaluation fitness ���ĵ��G�� */
	int current_run;							/* ��e�B�� run �� */

	void Init();           /* ���ͪ�ldim*pop_size�Ӹs��� */
	void Mutation();       /* ����donor�� */
	void Crossover();      /* ��� & donor�� ��e�ͦ�recent�� */
	void Evaluation();     /* �p��recent�Ѫ� fitness */
	void Determination();  /* update��(��� or recent��)�i�����U�@�N��
						   �Aupdate best_fit */
	void ParaAdaptation(); /* ��s mCR & mF */
	void LPSR();		   /* Linear Population Size Reduction */		
};

#endif
