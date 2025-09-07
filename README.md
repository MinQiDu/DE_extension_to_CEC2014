# MULTITHREADING Implement DE extension for Solving CEC2014 30 Benchmark Functions

## ( I ) Introduction

- **Programming language:** C++
- **Metaheuristic algorithm:**    
DE,    
JADE (Adaptive DE),    
SHADE (Success-History based parameter Adaptation for DE),    
L-SHADE (SHADE Using  Linear Population Size Reduction),   
iL-SHADE (Improved L-SHADE)
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

### `L-SHADE` & `iL-SHADE`
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

For L-SHADE & iL-SHADE:
```
.exe {dim} {pop_size} {mCR} {mF} {H} {p} {func_id} {archive_flag} LSHADE/ILSHADE
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

#### iL-SHADE
- `iLSHADE_integrated_fitness.txt`
  - Appended summary of all function tests
- `iLSHADE_fitness_func{fid}_dim{dim}_archive_{true|false}.txt`
  - Summary per run: best fitness per run, avg fitness
- `iLSHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
  - Best fitness at each evaluation
- `plot_iLSHADE_func{fid}_dim{dim}_archive_{true|false}.plt`
  - Gnuplot script
- `iLSHADE_cvg_plot_func{fid}_dim{dim}_archive_{true|false}.png`
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

// Run iLSHADE for function f6, dim=30, with archive
./.exe 30 100 0.5 0.5 100 0.05 6 1 ILSHADE
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

// generate plot of iL-SHADE in function {func_id}
gnuplot plot_iLSHADE_func{fid}_dim{dim}_archive_{true|false}.plt
```
```
// 當有以下文字紀錄:
// `DE_fitness_avg_cvg{fid}_dim{dim}.txt`
// `JADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
// `SHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
// `LSHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`
// `iLSHADE_fitness_avg_cvg{fid}_dim{dim}_archive_{true|false}.txt`

// generate comparison plot between DE, JADE, SHADE, L-SHADE and iL-SHADE
gnuplot plot_compare_func{fid}_dim{dim}.plt
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
│   ├── iLSHADE.cpp / iLSHADE.h
│   ├── DE_fileoutput.h / JADE_fileoutput.h / SHADE_fileoutput.h / LSHADE_fileoutput.h / iLSHADE_fileoutput.h
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
│   ├── LSHADE
│   │  ├── LSHADE_integrated_fitness.txt
│   │  ├── LSHADE_fitness_func*.txt
│   │  ├── LSHADE_fitness_avg_cvg*.txt
│   │  ├── LSHADE_cvg_plot*.png
│   │  └── plot_LSHADE*.plt
│   ├── iLSHADE
│   │  ├── iLSHADE_integrated_fitness.txt
│   │  ├── iLSHADE_fitness_func*.txt
│   │  ├── iLSHADE_fitness_avg_cvg*.txt
│   │  ├── iLSHADE_cvg_plot*.png
│   │  └── plot_iLSHADE*.plt
│   └── Compare ← dim30, dim50 and dim100
│      ├── all_plot_compare_func{fid}_dim{dim}.plt
│      └── all_compare_avg_cvg_plot_func{fid}_dim{dim}.png ← convergence curves comparison of DE, JADE, SHADE, L-SHADE and iL-SHADE with archive
├── docs/
│   ├── run_de_dim30.bat
│   ├── run_jade_dim30_archive_false.bat
│   ├── run_jade_dim30_archive_true.bat
│   └── run_shade_dim30_archive_true.bat
├── DE_extension_ExperimentResults.xlsx ← comparison results of DE, JADE, SHADE, L-SHADE and iL-SHADE
└── README.md
```

---

## ( VII ) Experimental Results

### **Experimental Results**
<p align="center">
<img src="results/KEY.png" width="25%"/>
</p>
<p align="center">
  <img src="results/EXPERIMENTAL RESULTS OF 10-DIMENSIONAL PROBLEMS.png" width="100%"/>
</p>
<p align="center">
  <img src="results/EXPERIMENTAL RESULTS OF 30-DIMENSIONAL PROBLEMS.png" width="100%"/>
</p>
<p align="center">
  <img src="results/EXPERIMENTAL RESULTS OF 50-DIMENSIONAL PROBLEMS.png" width="100%"/>
</p>
<p align="center">
  <img src="results/EXPERIMENTAL RESULTS OF 100-DIMENSIONAL PROBLEMS.png" width="100%"/>
</p>

---

### **Compared Convergence Plot of DE & JADE & SHADE & L-SHADE & iL-SHADE**
### dimension 30
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func1_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func2_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func3_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func4_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func5_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func6_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func7_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func8_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func9_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func10_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func11_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func12_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func13_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func14_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func15_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func16_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func17_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func18_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func19_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func20_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func21_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func22_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func23_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func24_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func25_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func26_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func27_dim30.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func28_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func29_dim30.png" width="30%"/>
  <img src="results/Compare/dim30/with_archive/all_compare_avg_cvg_plot_func30_dim30.png" width="30%"/>
</p>

---

### dimension 50
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func1_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func2_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func3_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func4_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func5_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func6_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func7_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func8_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func9_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func10_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func11_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func12_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func13_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func14_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func15_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func16_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func17_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func18_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func19_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func20_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func21_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func22_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func23_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func24_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func25_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func26_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func27_dim50.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func28_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func29_dim50.png" width="30%"/>
  <img src="results/Compare/dim50/with_archive/all_compare_avg_cvg_plot_func30_dim50.png" width="30%"/>
</p>

---
### dimension 100
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func1_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func2_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func3_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func4_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func5_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func6_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func7_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func8_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func9_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func10_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func11_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func12_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func13_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func14_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func15_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func16_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func17_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func18_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func19_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func20_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func21_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func22_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func23_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func24_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func25_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func26_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func27_dim100.png" width="30%"/>
</p>
<p align="center">
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func28_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func29_dim100.png" width="30%"/>
  <img src="results/Compare/dim100/with_archive/all_compare_avg_cvg_plot_func30_dim100.png" width="30%"/>
</p>

---

## ( VIII ) Observations
JADE
- JADE performs stably across diverse multimodal functions
- Archive-less setting still converges in many cases
- f5, f6 remain challenging, showing need for deeper exploitation
- f8 is a boundary sensitive function. It's essential to make boundary control

SHADE
- Performs more robust global search than JADE; better for most multimodal functions
比 JADE 更具全域搜尋能力，適合處理多峰問題
- Converges faster than JADE on f1–f6, but may fall into local optima
在 f1～f6 上比 JADE 收斂快，但也更容易陷入局部最佳
- Performance sensitive to memory size H; too small causes oscillation, too large weakens adaptation
效能受記憶長度 H 影響，H 太小容易震盪，太大則失去自適應性
- Archive-free mode still maintains acceptable convergence
關閉 Archive 時仍可維持基本收斂品質

L-SHADE
- Population reduction speeds up convergence, especially in high dimensions
縮減人口數使收斂速度加快，特別是在高維問題上效果明顯
- Shows faster convergence than SHADE on most functions, but slightly less stable
多數函數收斂比 SHADE 快，但穩定性略低
- Highly sensitive to initial population size (D × r_initpop)
對初始人口數較敏感，須根據 D 動態調整
- Outstanding performance on f1–f5; struggles more with multimodal functions f7–f9
在 f1～f5 表現突出，但在多峰的 f7～f9 有收斂困難

iL-SHADE
- Early-phase stability by capping F (piecewise 0.7→0.8→0.9) and flooring CR (piecewise 0.5→0.25); this raises early success rate and prevents boundary overshoot.
透過分段限制 F 上限（前期 0.7→0.8→0.9）與設定 CR 下限 (前期 0.5→0.25)，提升初期成功率、避免越界與步長失控。
- Linear p schedule (0.2 → 0.1) by nfes/max_nfes balances exploration then exploitation; shows stronger performance than L-SHADE especially in high-D.
以 p 線性排程 (0.2 降至 0.1) 平衡前期探索與後期開發；在高維問題上比 L-SHADE 更有優勢。
- Smoothed memory update (blend previous memory with current success-weighted means) reduces parameter oscillation and improves convergence stability.
平滑化記憶更新機制（將前一代記憶與本代成功加權均值混合）可降低參數震盪、提升收斂穩定度。
- Keeps a high-parameter slot (e.g., MF=0.9, MCR=0.9) to allow occasional large moves without destabilizing early search.
在 MCR & MF 保留一個高參數記憶槽（如 MF=0.9、MCR=0.9），在不破壞穩定性的前提下偶爾進行大步躍遷。
- Less sensitive to H than SHADE due to smoothing, but extreme H still matters; overall wins more Wilcoxon pairwise cases vs L-SHADE on CEC14 (notably D=50,100).
因為有平滑機制，對 H 的敏感度低於 SHADE，但極端 H 仍影響表現；在 CEC14 上相較 L-SHADE 統計上有較多勝出案例（特別是 D=50、100）。

---

## ( IX ) Key Features

JADE
- Adaptive control of parameters (mCR, mF)
- Archive mechanism toggle
- Cauchy/Normal-based parameter sampling
- Flexible benchmark support (13 functions)
- Transposed fitness output for convergence plotting
- Gnuplot automation for result visualization

SHADE
- Historical memory for adaptive mCR and mF update
利用歷史記憶調整參數 mCR 和 mF
- Parameter sampling with Cauchy (mF) and Normal (mCR) distributions
使用 Cauchy（mF）與 Normal（mCR）進行參數抽樣
- Toggleable archive to enhance diversity and avoid degeneration
可開關的 Archive 強化多樣性並避免退化
- Adjustable memory size H for adaptation flexibility
記憶長度 H 可調，影響演化適應性
- Supports all 13 benchmark functions (CEC14 func1–func13)
支援 CEC14 函數 1～13
- Integrated convergence recording and gnuplot script generation
收斂紀錄整合與自動生成繪圖腳本

SHADE
- All features from SHADE
繼承 SHADE 所有特性
- Implements Linear Population Size Reduction (LPSR)
實作「線性人口縮減」策略（LPSR）
- Ideal for high-dimensional problems with reduced computational overhead
適合高維問題，能有效減少計算負擔
- Dynamically updates population size based on iteration progress
根據迭代進度動態調整人口數
- More aggressive convergence in early stages, focused refinement later
初期加強探索，後期集中局部優化

iL-SHADE
- Inherits L-SHADE core: current-to-pbest/1/bin, success-history memory, external archive, and **LPSR**.  
  繼承 L-SHADE 核心：current-to-pbest/1/bin、成功歷史記憶、外部檔案庫與 **LPSR**。
- **p scheduling by nfes:**  
  `p = p_max - ((p_max - p_min) / max_nfes) * nfes` ，其中 `p_max = 0.2`、`p_min = 0.1`；並且強制 `p >= 2/NP`。  
  **以評估次數排程 p：** 線性由 `0.2` 降至 `0.1`，同時保留 `p >= 2/NP` 的安全下限。
- **Guardrails for parameters:** early **F upper-bound** and **CR lower-bound** schedule.  
  **參數護欄：** 早期對 `F` 設上限、對 `CR` 設下限（例如：前 25% 預算 `F <= 0.7`、`CR >= 0.5`；前 50% `F <= 0.8`；前 75% `F <= 0.9`，之後放寬到常規）。
- **Smoothed memory update:** blend previous `M_F`, `M_CR` with success-weighted means (EMA-like) to avoid sudden shifts.  
  **平滑記憶更新：** 將前一代的 `M_F`、`M_CR` 與本代成功加權均值混合，降低參數震盪。
- **Fixed high-parameter memory cell** (e.g., `M_F = 0.9`, `M_CR = 0.9`) for occasional aggressive trials.  
  **固定高參數記憶槽：** 例如 `M_F = 0.9`、`M_CR = 0.9`，保留偶發的大步探索。




---

## ( X ) Skills Demonstrated

- Advanced C++ metaheuristic implementation
- Benchmark-driven experimental design
- Automated convergence analysis and plotting
- Command-line configuration and parameter tuning

SHADE
- Advanced adaptive DE mechanism with historical memory
利用歷史記憶實作進階 DE 自適應機制
- Cauchy & Normal sampling strategy for robustness
採用 Cauchy 與 Normal 抽樣法提升健壯性
- Archive interaction logic and memory update implementation
Archive 管理與記憶更新策略設計
- Sensitivity analysis for parameter H and archive size
分析參數 H 與 Archive 對演化行為的影響

LSHADE
- Population control logic with real-time adjustment
即時調整人口數的控制邏輯實作
- Efficient convergence for large-D problems
在高維問題中實現高效收斂
- Modular parameter pipeline and memory-safe coding
模組化參數流程與記憶體安全設計
- Multithread-compatible benchmarking structure
支援多執行緒的 benchmark 架構設計

iL-SHADE
- **Budget-aware scheduling:** implemented nfes-based **p** schedule and staged **F/CR** guardrails.  
  **預算導向參數排程：** 以 nfes 實作 **p** 線性排程與分段 **F/CR** 護欄。
- **Smoothed success-history memory:** blended updates for \(M_F, M_{CR}\) with weighted means of SF/SCR, reducing variance.  
  **平滑成功史記憶：** 以成功加權均值並與既有記憶混合更新 \(M_F, M_{CR}\)，降低方差。
- **High-parameter slot injection:** maintained a fixed \((M_F,M_{CR})\) cell to enable controlled large steps.  
  **高參數槽注入：** 維持固定 \((M_F,M_{CR})\) 記憶槽，提供可控的大步探索。

---

## ( XI ) References

JADE:   
[J.-Q. Zhang and A. C. Sanderson, “JADE: Adaptive Differential Evolution With Optional External Archive,” _IEEE Transactions on Evolutionary Computation_, vol. 13, no. 5, pp. 945–958, 2009.](http://ieeexplore.ieee.org/document/5208221/)   
SHADE:    
[R. Tanabe and A. Fukunaga, “Success-History Based Parameter Adaptation for
Differential Evolution,” in _Proceedings of IEEE Congress on Evolutionary Computation_, pp. 71-78, 2013.](http://ieeexplore.ieee.org/document/6557555/)   
L-SHADE:   
[R. Tanabe and A. Fukunaga, “Improving the search performance of SHADE using linear population size reduction,” in _proceedings of IEEE Congress on Evolutionary Computation_, pp. 1658-1665, 2014.](https://ieeexplore.ieee.org/document/6900380)     
iL-SHADE:   
[J. Brest, M. S. Maučec, and B. Bošković, “iL-SHADE: Improved L-SHADE algorithm for single objective real-parameter optimization,” in _Proceedings of IEEE Congress on Evolutionary Computation_, pp. 1188–1195, 2016.](http://ieeexplore.ieee.org/document/7743922/)
