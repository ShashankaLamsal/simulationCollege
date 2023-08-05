#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
int N = 10000;
int n_rand = 100;

using namespace std;
double func(double r);

double integ()
{
    double a, b;
    double sum = 0;

    int i;
    a = 0;
    b = 3.1416;
    for (i = 0; i < n_rand; i++)
    {
        double r = (double)rand() / RAND_MAX * (b - a) + a;
        sum += func(r);
    }
    float result = (b - a) / n_rand * sum;

    return result;
}

int main()
{
    int j = 0;

    float mean, summ = 0, var_cal, var_summ = 0, var, var_sq;
    double answer[N], Num = 1000;

    // Variance
    for (j = 0; j < N; j++)
    {
        answer[j] = integ();
        summ += answer[j];
    }
    mean = summ / N;

    for (j = 0; j < N; j++)
    {
        var_cal = pow((answer[j] - mean), 2);
        var_summ += var_cal;
        var = var_summ / N;
    }
    // 95% confidence interval
    double final_result1, final_result2;
    final_result1 = mean - 1.96 * (var / sqrt(N));
    final_result2 = mean + 1.96 * (var / sqrt(N));

    // Variance
    cout << "Mean =" << mean << "\n";
    cout << "Variance =" << var << "\n";
    cout << "Result 1 =" << final_result1 << "\n";
    cout << "Result 2 =" << final_result2 << "\n";
}

double func(double r)
{
    return sqrt(1 + cos(r) * cos(r));
}
