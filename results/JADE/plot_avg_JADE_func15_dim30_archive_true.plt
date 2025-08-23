set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'
set output 'JADE_avg_cvg_plot_func15_dim30_archive_true.png'
set title 'JADE Average Convergence Plot (f15, dim30, archive: true)'
set xlabel 'Evaluation times'
set ylabel 'Average Best Fitness'
set grid
set label 'Avg best fitness: 7.02342' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'
set lmargin 10
set tmargin 5
plot 'JADE_fitness_avg_cvg15_dim30_archive_true.txt' with lines title 'Average Best Fitness'
