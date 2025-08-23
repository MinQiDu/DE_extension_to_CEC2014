set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'
set output 'LSHADE_avg_cvg_plot_func8_dim30_archive_true.png'
set title 'LSHADE Average Convergence Plot (f8, dim30, archive: true)'
set xlabel 'Evaluation times'
set ylabel 'Average Best Fitness'
set grid
set label 'Avg best fitness: 6.96611e-16' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'
set lmargin 10
set tmargin 5
plot 'LSHADE_fitness_avg_cvg8_dim30_archive_true.txt' with lines title 'Average Fitness'
