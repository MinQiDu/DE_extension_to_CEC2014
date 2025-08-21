#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <random>    // For random number generation
#include <vector>
using namespace std;

class Benchmark
{
public:
    Benchmark(int _func_id);
	double Evaluate(const vector<double>& x) const;                 // Evaluate the benchmark function based on the function ID 1~13
	void GetBounds(double& lower_bound, double& upper_bound) const; // Get the bounds for the benchmark function based on the function ID

private:
    int func_id;
};
#endif


