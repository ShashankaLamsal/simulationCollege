#include <cmath>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main()
{

    // for sqrt(x^4+y)dx   , 0-8, 0-2
    int i, j;
    double a0, a1, b0, b1, N, r, func, sum = 0, mean, var, func1, x, y;
    a0 = 0, b0 = 8;
    a1 = 0, b1 = 2; // range
    N = 1000;       // sample size

    for (i = 0; i < 10000; i++)
    {
        func = 0;
        double y = (double)rand() / RAND_MAX * (b0 - a0) + a0;
        for (j = 0; j < 10000; j++)
        {
            x = (double)rand() / RAND_MAX * (b1 - a1) + a1;
            func = func + sqrt(pow(x, 4) + y);
        }
        func = (b1 - a1) * func / N;
        sum = sum + func;
    }

    sum = (b0 - a0) * sum / N;
    cout << "The value is:" << func;
}
