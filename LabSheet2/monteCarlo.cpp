#include <cmath>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

double integral(double a, double b)
{
    double func;
    double r = (double)rand() / RAND_MAX * (b - a) + a;
    func = func + sqrt(1 + pow(cos(r), 2));
    return func;
}

int main()
{

    // for sqrt(1+cosx^2)dx   , 0 to pi
    int i;
    double a, b, N, r, func = 0, mean, var, func1;
    a = 0, b = 3.1415; // range
    N = 1000;          // sample size

    for (i = 0; i < 1000; i++)
    {
        double r = (double)rand() / RAND_MAX * (b - a) + a;
        func = func + sqrt(1 + pow(cos(r), 2));
    }
    mean = func / N;

    func = (b - a) * func / N;
    cout << "The value is:" << func;
}
