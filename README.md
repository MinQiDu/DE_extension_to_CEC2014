# Implement DE extension for Solving CEC2014 30 Benchmark Functions

## ( I ) Introduction

- **Programming language:** C++
- **Metaheuristic algorithm:**    
DE,    
JADE (Adaptive DE),    
SHADE (Success-History based parameter Adaptation for DE),    
L-SHADE (SHADE Using  Linear Population Size Reduction)
- **Benchmark functions:** 30 Benchmark Functions from IEEE CEC2014 (f1 \~ f30)
- **Visualization:** Gnuplot
- **Configurable parameters:** dimension, population size, control parameters, func_id, archive on/off

---

## ( II ) Main Functionality

### `DE`
- `void RunALG(int dim, int pop_size, double CR, double F, int func_id)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/random/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

### `JADE`
- `void RunALG(int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/current-to-pbest/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover with boundary reflection and jittering*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

- `void ParaAdaptation()` *Adapts mCR and mF based on successful individuals*

### `SHADE`
- `void RunALG(int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/current-to-pbest/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover with boundary reflection and jittering*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

- `void ParaAdaptation()` *Adapts mCR and mF based on successful individuals*

### `L-SHADE`
- `void RunALG(int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/current-to-pbest/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover with boundary reflection and jittering*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

- `void ParaAdaptation()` *Adapts mCR and mF based on successful individuals*

- `void LPSR()` *Linear Population Size Reduction*

---

## ( III ) Input

### Command-line arguments:
For DE:
```
.exe {dim} {pop_size} {CR} {F} {func_id} DE
```

- `dim`: Problem dimensionality (e.g., 30)
- (NO USE) `pop_size`: Population size (e.g., 100)
- `CR`: Mean crossover rate (e.g., 0.5)
- `F`: Mean scaling factor F (e.g., 0.5)
- `func_id`: Benchmark function ID (1\~13)
- `algo_type`: Type of Algorithm

For JADE:
```
.exe {dim} {pop_size} {mCR} {mF} {c} {p} {func_id} {archive_flag} JADE
```

- `dim`: Problem dimensionality (e.g., 30)
- (NO USE) `pop_size`: Population size (e.g., 100)
- `mCR`: Mean crossover rate (e.g., 0.5)
- `mF`: Mean scaling factor F (e.g., 0.5)
- `c`: Adaptation constant (e.g., 0.1)
- `p`: Top p% for pbest selection (e.g., 0.1)
- `func_id`: Benchmark function ID (1\~13)
- `archive_flag`: Use archive (1 = true, 0 = false)
- `algo_type`: Type of Algorithm

For SHADE:
```
.exe {dim} {pop_size} {mCR} {mF} {H} {p} {func_id} {archive_flag} SHADE
```

- `dim`: Problem dimensionality (e.g., 30)
- (NO USE) `pop_size`: Population size (e.g., 100)
- `mCR`: Mean crossover rate (e.g., 0.5)
- `mF`: Mean scaling factor F (e.g., 0.5)
- `H`: History size of mCR & mF (e.g., 100)
- `p`: Top p% for pbest selection (e.g., 0.1)
- `func_id`: Benchmark function ID (1\~13)
- `archive_flag`: Use archive (1 = true, 0 = false)
- `algo_type`: Type of Algorithm

For L-SHADE:
```
.exe {dim} {pop_size} {mCR} {mF} {H} {p} {func_id} {archive_flag} LSHADE
```

- `dim`: Problem dimensionality (e.g., 30)
- (NO USE) `pop_size`: Population size (e.g., 100)
- `mCR`: Mean crossover rate (e.g., 0.5)
- `mF`: Mean scaling factor F (e.g., 0.5)
- `H`: History size of mCR & mF (e.g., 100)
- `p`: Top p% for pbest selection (e.g., 0.1)
- `func_id`: Benchmark function ID (1\~13)
- `archive_flag`: Use archive (1 = true, 0 = false)
- `algo_type`: Type of Algorithm
---

## ( IV ) Output

#### DE
- `DE_integrated_fitness.txt`
  - Appended summary of all function tests
- `DE_fitness_func{fid}_dim{dim}.txt`
  - Summary per run: best fitness per run, avg fitness
- `DE_fitness_avg_cvg{fid}_dim{dim}.txt`
  - Best fitness at each evaluation
- `plot_DE_func{fid}_dim{dim}.plt`
  - Gnuplot script
- `DE_cvg_plot_func{fid}_dim{dim}.png`
  - Convergence plot

#### JADE
- `JADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `JADE_fitness_func{fid}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `JADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_JADE_func{fid}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `JADE_cvg_plot_func{fid}_dim{dim}_archive_{true|false}.png`
  - Convergence plot

#### SHADE
- `SHADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `SHADE_fitness_func{fid}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `SHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_SHADE_func{fid}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `SHADE_cvg_plot_func{fid}_dim{dim}_archive_{true|false}.png`
  - Convergence plot

#### L-SHADE
- `LSHADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `LSHADE_fitness_func{fid}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `LSHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_LSHADE_func{fid}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `LSHADE_cvg_plot_func{fid}_dim{dim}_archive_{true|false}.png`
  - Convergence plot

---

## ( V ) How to Compile & Run

### Compile

```bash
方法1 in VisualStudio : Ctrl + Shift + B 
```
```MSYS2
方法2 in MSYS2 : g++ main.cpp DE.cpp JADE.cpp LSHADE.cpp SHADE.cpp cec14_test_func.cpp -o run.exe -std=c++11
```

### Run

```bash
// Run DE for function f6, dim=30
./.exe 30 100 0.5 0.5 0.1 0.1 6 0 DE

// Run JADE for function f6, dim=30, with archive
./.exe 30 100 0.5 0.5 0.1 0.1 6 1 JADE 

// Run SHADE for function f6, dim=30, with archive
./.exe 30 100 0.5 0.5 100 0.05 6 1 SHADE

// Run LSHADE for function f6, dim=30, with archive
./.exe 30 100 0.5 0.5 100 0.05 6 1 LSHADE
```
**Notice: You can click .bat files in folder docs to run jade.exe**

### Visualize
**Generates PNG image of convergence plot.**
```bash
// generate plot of DE in function {func_id}
gnuplot plot_DE_func{fid}_dim{dim}.plt

// generate plot of JADE in function {func_id}
gnuplot plot_JADE_func{fid}_dim{dim}_archive_{true|false}.plt

// generate plot of SHADE in function {func_id}
gnuplot plot_SHADE_func{fid}_dim{dim}_archive_{true|false}.plt

// generate plot of L-SHADE in function {func_id}
gnuplot plot_LSHADE_func{fid}_dim{dim}_archive_{true|false}.plt
```
```
// 當有以下文字紀錄:
// `DE_fitness_avg_cvg{fid}_dim{dim}.txt`
// `JADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
// `SHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
// `LSHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`

// generate comparison plot between DE, JADE, SHADE and LSHADE
gnuplot plot_compare_func{fid}_dim{dim}_archive_{true|false}.plt
```

---

## ( VI ) File Structure

```
DE_extension_to_CEC2014/
├── DE_extension_to_CEC2014/ ← source codes
│   ├── main.cpp
│   ├── DE.cpp / DE.h
│   ├── JADE.cpp / JADE.h
│   ├── SHADE.cpp / SHADE.h
│   ├── LSHADE.cpp / LSHADE.h
│   ├── DE_fileoutput.h / JADE_fileoutput.h / SHADE_fileoutput.h / LSHADE_fileoutput.h
│   ├── cec14_test_func.cpp / cec14_test_func.h
│   └── input_data ← files for cec14_test_func.cpp
├── results/ ← output files (.txt, .png)
│   ├── DE
│   │  ├── DE_integrated_fitness.txt
│   │  ├── DE_fitness_func*.txt
│   │  ├── DE_fitness_avg_cvg*.txt
│   │  ├── DE_cvg_plot*.png
│   │  └── plot_DE*.plt
│   ├── JADE
│   │  ├── JADE_integrated_fitness.txt
│   │  ├── JADE_fitness_func*.txt
│   │  ├── JADE_fitness_avg_cvg*.txt
│   │  ├── JADE_cvg_plot*.png
│   │  └── plot_JADE*.plt
│   ├── SHADE
│   │  ├── SHADE_integrated_fitness.txt
│   │  ├── SHADE_fitness_func*.txt
│   │  ├── SHADE_fitness_avg_cvg*.txt
│   │  ├── SHADE_cvg_plot*.png
│   │  └── plot_SHADE*.plt
│   └── Compare
│      ├── plot_compare_func{fid}_dim{dim}_archive_{true|false}.plt
│      ├── compare_avg_cvg_plot_func{fid}_dim{dim}_archive_{true|false}.png ← convergence curves comparison of DE, JADE, SHADE and LSHADE
│      ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
│      ├── all_plot_compare_func{fid}_dim{dim}.plt
│      └── all_compare_avg_cvg_plot_func{fid}_dim{dim}.png ← convergence curves comparison of DE, JADE, SHADE and LSHADE in both with & w/o archive
├── docs/
│   ├── run_de_dim30.bat
│   ├── run_jade_dim30_archive_false.bat
│   ├── run_jade_dim30_archive_true.bat
│   └── run_shade_dim30_archive_true.bat
├── DE_extension_ExperimentResults.xlsx ← comparison results of DE, JADE, SHADE and LSHADE
└── README.md
```

---

## ( VII ) Experimental Results

### **Compared Convergence Plot of DE & JADE & SHADE & L-SHADE**
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func1_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func2_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func3_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func4_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func5_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func6_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func7_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func8_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func9_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func10_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func11_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func12_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func13_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func14_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func15_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func16_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func17_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func18_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func19_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func20_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func21_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func22_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func23_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func24_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func25_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func26_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func27_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func28_dim30.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func29_dim30.png" width="49%"/>
  <img src="results/Compare/with_without_archive/all_compare_avg_cvg_plot_func30_dim30.png" width="49%"/>
</p>

---

## ( VIII ) Observations

- JADE performs stably across diverse multimodal functions
- Archive-less setting still converges in many cases
- f5, f6 remain challenging, showing need for deeper exploitation
- f8 is a boundary sensitive function. It's essential to make boundary control

---

## ( IX ) Key Features

- Adaptive control of parameters (mCR, mF)
- Archive mechanism toggle
- Cauchy/Normal-based parameter sampling
- Flexible benchmark support (13 functions)
- Transposed fitness output for convergence plotting
- Gnuplot automation for result visualization

---

## ( X ) Skills Demonstrated

- Advanced C++ metaheuristic implementation
- Benchmark-driven experimental design
- Automated convergence analysis and plotting
- Command-line configuration and parameter tuning

---

## ( XI ) References

JADE:   
[J.-Q. Zhang, A.C. Sanderson, “JADE: Adaptive Differential Evolution With Optional External Archive,” _IEEE Transactions on Evolutionary Computation_, vol. 13, no. 5, pp. 945–958, 2009.](http://ieeexplore.ieee.org/document/5208221/)   
SHADE:    
[R. Tanabe, A. Fukunaga, “Success-History Based Parameter Adaptation for
Differential Evolution,” _IEEE Transactions on Evolutionary Computation_, pp. 71-78, 2013.](http://ieeexplore.ieee.org/document/6557555/)   
L-SHADE:   
[R. Tanabe, A. Fukunaga, “Improving the search performance of SHADE using linear population size reduction,” _IEEE Congress on Evolutionary Computation_, pp. 1658-1665, 2014.](https://ieeexplore.ieee.org/document/6900380)
