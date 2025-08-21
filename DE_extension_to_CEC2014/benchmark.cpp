#include "benchmark.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <numeric> // For std::accumulate

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Benchmark::Benchmark(int _func_id)
    : func_id(_func_id)
{
}

double Benchmark::Evaluate(const vector<double>& x) const // Evaluate the benchmark function based on the function ID
{
    const int D = static_cast<int>(x.size());
    double sum = 0.0;
    double prod;
    double temp;
    switch (func_id) {
    case 1: // Sphere
        return std::accumulate(x.begin(), x.end(), 0.0, [](double acc, double xi) {
            return acc + xi * xi;
        });

    case 2: // Schwefel 2.22
        sum = 0.0;
        prod = 1.0;
        for (const double xi : x) {
            sum += std::abs(xi);
            prod *= std::abs(xi);
        }
        return sum + prod;

    case 3: // Schwefel 1.2
        sum = 0.0;
        for (int i = 0; i < D; ++i) {
            temp = 0.0; // Reset temp for each i
            for (int j = 0; j <= i; ++j) temp += x[j];
            sum += temp * temp;
        }
        return sum;

    case 4: // Step (max_i |x_i|)
    {
        double max_abs = 0.0;
        for (const double xi : x) {
            double abs_xi = std::abs(xi);
            if (abs_xi > max_abs) max_abs = abs_xi;
        }
        return max_abs;
    }

    case 5: // Rosenbrock
        for (int i = 0; i < D - 1; ++i)
            sum += 100 * pow(x[i + 1] - x[i] * x[i], 2) + pow(x[i] - 1, 2);
        return sum;

    case 6: // Step function
    {
        sum = 0.0;
        for (const double xi : x)
        {
            sum += pow(floor(xi + 0.5), 2);
        }
        return sum;
    }

    case 7: { // Noisy Quartic
        sum = 0.0;
        for (int i = 0; i < D; ++i)
            sum += (i + 1) * std::pow(x[i], 4);

        // Use thread_local random engine for thread safety
        thread_local std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        sum += dist(gen); // Add random noise
        return sum;
    }

    case 8: // Schwefel 2.26
        sum = 0.0;
        //for (int i = 0; i < D; ++i)
        //    sum += x[i] * sin(sqrt(fabs(x[i])));
        //return 418.98288727243369 * D - sum; //418.98288727243369
        for (int i = 0; i < D; ++i)  
        {  
            double shifted_x = x[i] + 4.209687462275036e+002; // Create a shifted copy of x[i]  
            if (shifted_x > 500) {  
                sum -= (500.0 - fmod(shifted_x, 500)) * sin(sqrt(500.0 - fmod(shifted_x, 500)));  
                double tmp = (shifted_x - 500.0) / 100;  
                sum += tmp * tmp / D;  
            } else if (shifted_x < -500) {  
                sum -= (-500.0 + fmod(fabs(shifted_x), 500)) * sin(sqrt(500.0 - fmod(fabs(shifted_x), 500)));  
                double tmp = (shifted_x + 500.0) / 100;  
                sum += tmp * tmp / D;  
            } else {  
                sum -= shifted_x * sin(sqrt(fabs(shifted_x)));  
            }  
        }
		return sum + 4.189828872724338e+002 * D; //418.98288727243369 * D;

    case 9: // Rastrigin
        for (const double xi : x)
            sum += xi * xi - 10 * cos(2 * M_PI * xi) + 10;
        return sum;

    case 10: // Ackley
    {
        double sum1 = 0.0, sum2 = 0.0;
        for (const double xi : x) {
            sum1 += xi * xi;
            sum2 += cos(2 * M_PI * xi);
        }
        return -20.0 * exp(-0.2 * sqrt(sum1 / D)) - exp(sum2 / D) + 20.0 + exp(1.0);
    }

    case 11: // Griewank
    {
        double sum_sq = 0.0;
        double prod_cos = 1.0;
        for (int i = 0; i < D; ++i) {
            sum_sq += x[i] * x[i];
            prod_cos *= cos(x[i] / sqrt(i + 1));
        }
        return 1 + sum_sq / 4000.0 - prod_cos;
    }

    case 12: // Generalized Penalized Function No.01
    {
        double sum1 = 0.0;
        double penalty = 0.0;
        const double a = 10.0;
        const double k = 100.0;
        const double m = 4.0;

        // 1. 計算 yi
        vector<double> y(D);
        for (int i = 0; i < D; ++i)
        {
            y[i] = 1 + 0.25 * (x[i] + 1);
        }

        // 2. 第一項：π/n × {...}
        sum1 += 10 * pow(sin(M_PI * y[0]), 2);
        for (int i = 0; i < D - 1; ++i)
        {
            double term = pow(y[i] - 1, 2) * (1 + 10 * pow(sin(M_PI * y[i + 1]), 2));
            sum1 += term;
        }
        sum1 += pow(y[D - 1] - 1, 2);
        double term1 = (M_PI / D) * sum1;

        // 3. 第二項：∑ u(xi, a, k, m)
        for (int i = 0; i < D; ++i)
        {
            if (x[i] > a)
                penalty += k * pow(x[i] - a, m);
            else if (x[i] < -a)
                penalty += k * pow(-x[i] - a, m);
            // else: penalty += 0;
        }

        return term1 + penalty;
    }

    case 13: {
        // f13: Generalized Penalized Function No.02
        double sum = 0.0;
        double penalty = 0.0;
        const double a = 5.0;
        const double k = 100.0;
        const double m = 4.0;

        // 第一項: sin^2(3πx₁)
        sum += sin(3.0 * M_PI * x[0]) * sin(3.0 * M_PI * x[0]);

        // 第二項: ∑_{i=1}^{D-1} [(x_i - 1)^2 * (1 + sin^2(3πx_{i+1}))]
        for (int i = 0; i < D - 1; ++i) 
        {
            double term = pow(x[i] - 1.0, 2) * (1 + pow(sin(3.0 * M_PI * x[i + 1]), 2));
            sum += term;
        }

        double term_last = pow(x[D - 1] - 1.0, 2) * (1.0 + pow(sin(2.0 * M_PI * x[D - 1]), 2));
        sum += term_last;

        for (int i = 0; i < D; ++i) {
            if (x[i] > a)
                penalty += k * pow(x[i] - a, m);
            else if (x[i] < -a)
                penalty += k * pow(-x[i] - a, m);
        }
        return 0.1 * sum + penalty;
    }

    default:
        return 0.0;
    }
}

void Benchmark::GetBounds(double& lower_bound, double& upper_bound) const // Get the bounds for the benchmark function based on the function ID
{
    switch (func_id)
    {
    case 1: case 3: case 4: case 6:
        lower_bound = -100; upper_bound = 100; break;
    case 2:
        lower_bound = -10; upper_bound = 10; break;
    case 5:
        lower_bound = -30; upper_bound = 30; break;
    case 7:
        lower_bound = -1.28; upper_bound = 1.28; break;
    case 8:
        lower_bound = -500; upper_bound = 500; break;
    case 9:
        lower_bound = -5.12; upper_bound = 5.12; break;
    case 10:
        lower_bound = -32; upper_bound = 32; break;
    case 11:
        lower_bound = -600; upper_bound = 600; break;
    case 12: case 13:
        lower_bound = -50; upper_bound = 50; break;
    default:
        lower_bound = -100; upper_bound = 100;
    }
}

