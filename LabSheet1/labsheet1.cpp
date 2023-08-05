#include <iostream>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    default_random_engine generator;
    exponential_distribution<double> distribution(0.2);
    generator.seed(23415);

    double mean = 0;
    int nSample = 100;

    ofstream fout("curve.csv");

    for (int i = 0; i < nSample; i++)
    {
        double r = distribution(generator);
        fout << r << "\n";
    }

    fout.close();
    return 0;
}