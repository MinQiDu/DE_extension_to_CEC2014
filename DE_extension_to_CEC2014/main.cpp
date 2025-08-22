#include "DE.h"
#include "JADE.h"
#include "SHADE.h"
#include "LSHADE.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	int dim = atoi(argv[1]);
	int pop_size = atoi(argv[2]);
	double mCR = atof(argv[3]); // adaptive parameter 1 (cross_rate)
	double mF = atof(argv[4]);  // adaptive parameter 2 (= F, donor_rate)
	double c = atof(argv[5]);   // adaptation rate c
	double p = atof(argv[6]);   // adaptation rate c and top % pop chosen for pbest
	int func_id = atoi(argv[7]);
	string algo_type = argv[9]; // DE or JADE or SHADE or LSHADE

	//transform(algo_type.begin(), // 防呆! 轉換algo_type成全大寫
	//	algo_type.end(),
	//	algo_type.begin(),
	//	toupper);

	if (func_id < 1 || func_id > 30)
	{
		cout << "Invalid function ID. Please enter a value between 1 and 30." << endl;
		return 1; // 結束程式
	}

	bool archive_flag; 					// 是否使用 archive list A
	string a = argv[8];					// 是否使用 archive list A
	if (a == "0")
	{
		archive_flag = false;			// 不使用 archive list A
	}
	else if (a == "1")
	{
		archive_flag = true;			// 使用 archive list A
	}
	else
	{
		cout << "Invalid input for archive list A. Please enter 0 or 1." << endl;
		return 1; // 結束程式
	}
	

	bool canrun = 0;

	while (canrun == 0)
	{
		canrun = 1;

		if (algo_type == "DE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | CR = " << mCR << " | F = " << mF << endl;
			algo_DE algo;
			algo.RunALG(dim, pop_size, mCR, mF, func_id);
		}

		else if (algo_type == "JADE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | mCR = " << mCR << " | mF = " << mF << " | c = " << c << " | p = " << p << " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
			algo_JADE algo;
			algo.RunALG(dim, pop_size, mCR, mF, c, p, func_id, archive_flag);
		}
		else if (algo_type == "SHADE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | mCR = " << mCR << " | mF = " << mF << " | MCR & MF size = " << c << " | p = " << p << " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
			algo_SHADE algo;
			algo.RunALG(dim, pop_size, mCR, mF, c, p, func_id, archive_flag);
		}
		else if (algo_type == "LSHADE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | mCR = " << mCR << " | mF = " << mF << " | MCR & MF size = " << c << " | p = " << p << " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
			algo_LSHADE algo;
			algo.RunALG(dim, pop_size, mCR, mF, c, p, func_id, archive_flag);
		}
		else
		{
			cout << "Invalid algorithm type. Please enter DE, JADE, SHADE or LSHADE." << endl;
			canrun = 0; // 不符合條件，重新輸入
			continue; // 跳過當前迴圈，重新輸入
		}
	}

}