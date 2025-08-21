# Implement DE extension for Solving 13 Benchmark Functions

## ( I ) Introduction

- **Programming language:** C++
- **Metaheuristic algorithm:** DE, JADE (Adaptive DE), SHADE (Success-History based parameter Adaptation for DE)
- **Benchmark functions:** 13 standard functions from IEEE CEC (f1 \~ f13)
- **Visualization:** Gnuplot
- **Configurable parameters:** iterations, dimension, population size, control parameters, archive on/off

---

## ( II ) Main Functionality

### `DE`
- `void RunALG(int iter, int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/random/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

### `JADE`
- `void RunALG(int iter, int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/current-to-pbest/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover with boundary reflection and jittering*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

- `void ParaAdaptation()` *Adapts mCR and mF based on successful individuals*

### `SHADE`
- `void RunALG(int iter, int dim, int pop_size, double mCR, double mF, double c, double p, int func_id, bool a_func)` *Main interface to run with given configuration*

- `void Init()` *Initializes population within bounds for selected benchmark function*

- `void Mutation()` *Applies DE/current-to-pbest/1 mutation with optional archive*

- `void Crossover()` *Performs binomial crossover with boundary reflection and jittering*

- `void Evaluation()` *Evaluates fitness using selected benchmark function*

- `void Determination()` *Selects better individuals and records improvements*

- `void ParaAdaptation()` *Adapts mCR and mF based on successful individuals*

---

## ( III ) Input

### Command-line arguments:
For DE:
```
DE_extension.exe iter dim pop_size CR F c p func_id archive_flag DE
```

- `iter`: Max number of iterations (e.g., 100)
- `dim`: Problem dimensionality (e.g., 30)
- `pop_size`: Population size (e.g., 100)
- `CR`: Mean crossover rate (e.g., 0.5)
- `F`: Mean scaling factor F (e.g., 0.5)
- `c`: NO USE
- `p`: NO USE
- `func_id`: Benchmark function ID (1\~13)
- `archive_flag`: NO USE
- `algo_type`: Type of Algorithm

For JADE:
```
DE_extension.exe iter dim pop_size mCR mF c p func_id archive_flag JADE
```

- `iter`: Max number of iterations (e.g., 100)
- `dim`: Problem dimensionality (e.g., 30)
- `pop_size`: Population size (e.g., 100)
- `mCR`: Mean crossover rate (e.g., 0.5)
- `mF`: Mean scaling factor F (e.g., 0.5)
- `c`: Adaptation constant (e.g., 0.1)
- `p`: Top p% for pbest selection (e.g., 0.1)
- `func_id`: Benchmark function ID (1\~13)
- `archive_flag`: Use archive (1 = true, 0 = false)
- `algo_type`: Type of Algorithm

For SHADE:
```
DE_extension.exe iter dim pop_size mCR mF H p func_id archive_flag SHADE
```

- `iter`: Max number of iterations (e.g., 100)
- `dim`: Problem dimensionality (e.g., 30)
- `pop_size`: Population size (e.g., 100)
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
- `DE_fitness_func{fid}_iter{iter}_dim{dim}.txt`
  - Summary per run: best fitness per run, avg fitness
- `DE_fitness_avg_cvg{fid}_iter{iter}_dim{dim}.txt`
  - Best fitness at each evaluation
- `plot_DE_func{fid}_iter{iter}_dim{dim}.plt`
  - Gnuplot script
- `DE_cvg_plot_func{fid}_iter{iter}_dim{dim}.png`
  - Convergence plot

#### JADE
- `JADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `JADE_fitness_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `JADE_fitness_avg_cvg{fid}_iter{iter}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_JADE_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `JADE_cvg_plot_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.png`
  - Convergence plot

#### SHADE
- `SHADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `SHADE_fitness_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `SHADE_fitness_avg_cvg{fid}_iter{iter}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_SHADE_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `SHADE_cvg_plot_func{fid}_iter{iter}_dim{dim}_archive_{true|false}.png`
  - Convergence plot

---

## ( V ) How to Compile & Run

### Compile

```bash
Ctrl + Shift + B in VisualStudio 
```

### Run


```bash
// Run DE for function f6, 100 iterations, dim=30
./DE_extension.exe 100 30 100 0.5 0.5 0.1 0.1 6 0 de

// Run JADE for function f6, 100 iterations, dim=30, no archive
./DE_extension.exe 100 30 100 0.5 0.5 0.1 0.1 6 0 jade 

// Run SHADE for function f6, 100 iterations, dim=30, no archive
./DE_extension.exe 100 30 100 0.5 0.5 100 0.05 6 0 shade
```
**Notice: You can click .bat files in folder docs to run jade.exe**

### Visualize

```bash
gnuplot plot_JADE_func6_iter100_dim30_archive_false.plt
```
**Generates PNG image of convergence plot.**

---

## ( VI ) File Structure

```
DE_extension_Benchmark/
├── main.cpp
├── DE.cpp / DE.h
├── JADE.cpp / JADE.h
├── SHADE.cpp / SHADE.h
├── Benchmark.cpp / Benchmark.h
├── DE_fileoutput.h / JADE_fileoutput.h / SHADE_fileoutput.h
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
│   ├── Compare
│   │  └── compare_avg_cvg_plot_func1~13_iter_dim_archive.png
├── docs/
│   ├── run_de_dim30.bat
│   ├── run_jade_dim30_archive_false.bat
│   ├── run_jade_dim30_archive_true.bat
│   └── run_shade_dim30_archive_true.bat
└── README.md
```

---

## ( VII ) Experimental Results

<img src="docs/benchmark.png" width="50%"/>

### **Compared Convergence Plot of DE & JADE & SHADE**
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func1_iter1500_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func2_iter2000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func3_iter5000_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func4_iter5000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func5_iter20000_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func5_iter3000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func6_iter100_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func6_iter1500_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func7_iter3000_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func8_iter1000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func8_iter9000_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func9_iter1000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func9_iter5000_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func10_iter2000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func10_iter500_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func11_iter3000_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func11_iter500_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func12_iter1500_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func12_iter500_dim30_archive_true.png" width="49%"/>
  <img src="results/Compare/compare_avg_cvg_plot_func13_iter1500_dim30_archive_true.png" width="49%"/>
</p>
<p align="center">
  <img src="results/Compare/compare_avg_cvg_plot_func13_iter500_dim30_archive_true.png" width="49%"/>
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