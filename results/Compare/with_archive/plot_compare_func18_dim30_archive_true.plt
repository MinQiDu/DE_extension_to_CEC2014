# === OUTPUT SETTING ===
set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'

# === Params (改這裡就好) ===
dim     = 30
func_id = 18
archive = "true"    # 也可以設成 "false" 看需求
max_eva = dim * 10000

# === 自動檔名 ===
outname = sprintf("compare_avg_cvg_plot_func%d_dim%d_archive_%s.png", func_id, dim, archive)
DEfile  = sprintf("DE_fitness_avg_cvg%d_dim%d.txt", func_id, dim)
JADEfile  = sprintf("JADE_fitness_avg_cvg%d_dim%d_archive_%s.txt", func_id, dim, archive)
SHADEfile = sprintf("SHADE_fitness_avg_cvg%d_dim%d_archive_%s.txt", func_id, dim, archive)
LSHADEfile= sprintf("LSHADE_fitness_avg_cvg%d_dim%d_archive_%s.txt", func_id, dim, archive)
set output outname

# %d 代表 整數 (decimal integer) → 用來填 func_id、dim 這類數字變數
# %s 代表 字串 (string) → 用來填 archive 這種文字變數 ("true" 或 "false")

# === TITLE AND AXIS ===
set title sprintf("Comparison of DE / JADE / SHADE / L-SHADE on f%d (dim=%d)", func_id, dim) \
    font "Verdana,15" offset 0,1.3
set xlabel 'Evaluation Times'
set ylabel 'Average Best Fitness'
set grid

# === SCALE ADJUSTMENT ===
set logscale y				# 放大趨近 0 的差異
set xrange [0:max_eva]		# 視收斂狀況選擇是否剪裁評估次數

# === LEGEND ===
# set key outside top center horizontal samplen 3
# 把圖例放在標題下方、置中、橫向排列
set key at screen 0.5,0.91 center top horizontal samplen 3 spacing 1.2 # 想再靠近標題就把 0.93 調大；想更往下就調小
set tmargin at screen 0.86
set lmargin at screen 0.1
set bmargin at screen 0.12
set rmargin at screen 0.93
set xtics offset 0,0.6              # 讓刻度文字離邊界遠一點（往上）

# lmargin/bmargin/rmargin/tmargin 都可以用 絕對值 (像素) 或 相對螢幕比例 at screen 來調整


# === PLOT FOUR ALGORITHMS ===
plot \
    DEfile     with lines linewidth 2 linecolor rgb '#6495ED' title 'DE', \
    JADEfile   with lines linewidth 2 linecolor rgb '#DC143C' title 'JADE', \
    SHADEfile  with lines linewidth 2 linecolor rgb '#FFA07A' title 'SHADE', \
    LSHADEfile with lines linewidth 2 linecolor rgb '#20B2AA' title 'L-SHADE'