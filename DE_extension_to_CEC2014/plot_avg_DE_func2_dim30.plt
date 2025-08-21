set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'
set output 'DE_avg_cvg_plot_func2_dim30.png'
set title 'DE Average Convergence Plot (f2, dim30)'
set xlabel 'Evaluation times'
set ylabel 'Average Best Fitness'
set grid
set label 'Avg best fitness: inf' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'
set lmargin 10
set tmargin 5
plot 'DE_fitness_avg_cvg2_dim30.txt' with lines title 'Average Best Fitness'
