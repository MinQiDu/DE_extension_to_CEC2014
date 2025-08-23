#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void SHADE_FileOutput(
	const int run,
    const std::vector<double>& best_fit_record,
    const std::vector<std::vector<double>>& eva_fit_record,
    int func_id, int dim, int pop_size,
    double _mCR, double _mF, int H, double p,
    bool archive_flag, double avg_best_fit
) {
	// ===== 產生 .txt 的程式碼 =====
	// 輸出每 run 運行的最佳 fitness 到 SHADE_fitness_func_dim_archive_.txt
	ofstream output_file("SHADE_fitness_func" + to_string(func_id) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".txt", ios::out);
	if (!output_file) {
		cerr << "Error opening output file." << endl;
		return;
	}
	output_file << "SHADE | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size
		<< " | mCR = " << _mCR << " | mF = " << _mF << " | MCR & MF size = " << H << " | p = " << p
		<< " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
	output_file << "Avg Best fitness: " << avg_best_fit << endl;
	for (int i = 0; i < run; ++i) {
		output_file << " | Best fitness run " << (i + 1) << ": " << best_fit_record[i] << endl;
	}
	output_file.close();

	// 輸出整合結果到 SHADE_integrated_fitness.txt
	ofstream integrated_output("SHADE_integrated_fitness.txt", ios::app);
	if (!integrated_output) {
		cerr << "Error opening integrated output file." << endl;
		return;
	}
	integrated_output << "SHADE | func_id = " << func_id << " | dim = " << dim << " | pop_size = " << pop_size
		<< " | mCR = " << _mCR << " | mF = " << _mF << " | MCR & MF size = " << H << " | p = " << p
		<< " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
	integrated_output << "Avg Best fitness: " << avg_best_fit << endl;
	integrated_output.close();

	///* 出圖(每一 run 分開) */
	//// 輸出每 run 運行的 fitness 到 SHADE_fitness_cvg.txt
	//ofstream cvg_file("SHADE_fitness_cvg" + to_string(func_id) + "_iter" + to_string(iter) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".txt");
	//if (!cvg_file) {
	//	cerr << "Error opening fitness convergence file." << endl;
	//	return;
	//}

	//// 先轉置輸出：每一列是 iteration，欄為每 run
	//for (int t = 0; t < iter; ++t) {
	//	for (int r = 0; r < run; ++r) {
	//		cvg_file << iter_fit_record[r][t];
	//		if (r != run - 1) cvg_file << " ";
	//	}
	//	cvg_file << "\n";
	//}
	//cvg_file.close();

	//// ===== 在這裡填入你產生 .plt 的程式碼 =====
	//// 產生 plot_SHADE.plt 畫出收斂圖
	//ofstream plot_file("plot_SHADE_func" + to_string(func_id) + "_iter" + to_string(iter) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".plt");
	//if (!plot_file) {
	//	cerr << "Error opening plot file." << endl;
	//	return;
	//}
	//plot_file << "set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'\n";
	//plot_file << "set output 'SHADE_cvg_plot" << "_func" << func_id << "_iter" << iter << "_dim" << dim << "_archive_" << (archive_flag ? "true" : "false") << ".png'\n";
	//plot_file << "set title 'SHADE Convergence Plot" << " (f" << func_id << ", iter" << iter << ", dim" << dim << ", archive: " << (archive_flag ? "true" : "false") << ")'\n";
	//plot_file << "set xlabel 'Iteration'\n";
	//plot_file << "set ylabel 'Best Fitness'\n";
	//plot_file << "set grid\n";
	//plot_file << "set label 'Avg best fitness: " << avg_best_fit << "' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'\n";
	//plot_file << "set lmargin 10\n";
	//plot_file << "set tmargin 5\n";
	//plot_file << "plot ";
	//for (int i = 2; i <= run + 1; ++i) {
	//	plot_file << "'SHADE_fitness_cvg" << to_string(func_id) << "_iter" << to_string(iter) << "_dim" << to_string(dim) << "_archive_" << (archive_flag ? "true" : "false") << ".txt' using :" << i
	//		<< " with lines title 'Run " << (i - 1) << "'";
	//	if (i != run + 1) plot_file << ", ";
	//}
	//plot_file << "\n";
	//plot_file.close();

	/* 出圖(所有 run 平均) */
	ofstream SHADE_fitness_cvg_avg_file("SHADE_fitness_avg_cvg" + to_string(func_id) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".txt");
	if (!SHADE_fitness_cvg_avg_file) {
		cerr << "Error opening average fitness convergence file." << endl;
		return;
	}
	// 計算每一個 evaluation 的平均 fitness
	int max_eva = eva_fit_record[0].size();
	for (int t = 0; t < max_eva; ++t) {
		double avg_fit = 0.0;
		for (int r = 0; r < run; ++r) {
			avg_fit += eva_fit_record[r][t];
		}
		SHADE_fitness_cvg_avg_file << avg_fit / run << "\n"; // 寫入平均值
	}
	SHADE_fitness_cvg_avg_file.close();

	// 產生 plot_avg_JADE.plt 畫出平均收斂圖
	ofstream avg_plot_file("plot_avg_SHADE_func" + to_string(func_id) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".plt");
	if (!avg_plot_file) {
		cerr << "Error opening average plot file." << endl;
		return;
	}
	avg_plot_file << "set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'\n";
	avg_plot_file << "set output 'SHADE_avg_cvg_plot" << "_func" << func_id << "_dim" << dim << "_archive_" << (archive_flag ? "true" : "false") << ".png'\n";
	avg_plot_file << "set title 'SHADE Average Convergence Plot" << " (f" << func_id << ", dim" << dim << ", archive: " << (archive_flag ? "true" : "false") << ")'\n";
	avg_plot_file << "set xlabel 'Evaluation times'\n";
	avg_plot_file << "set ylabel 'Average Best Fitness'\n";
	avg_plot_file << "set grid\n";
	avg_plot_file << "set label 'Avg best fitness: " << avg_best_fit << "' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'\n";
	avg_plot_file << "set lmargin 10\n";
	avg_plot_file << "set tmargin 5\n";
	avg_plot_file << "set logscale y\n";
	avg_plot_file << "plot 'SHADE_fitness_avg_cvg" << to_string(func_id) << "_dim" << to_string(dim) << "_archive_" << (archive_flag ? "true" : "false") << ".txt' with lines title 'Average Fitness'\n";
	avg_plot_file.close();
}
