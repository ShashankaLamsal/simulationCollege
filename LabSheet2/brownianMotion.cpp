// labsheet 2 stock market prediction

#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    double S[16][1000];
    // initail stock for CBA-AU
    double mu = 0.0518;      // expected annual return
    double sigma = 0.1663;   // expected annual volatility
    double dt = 1.0 / 250.0; // time increment assuming 250 days

    double var_cal[16] = {0}, var = 0, aa = 0;

    int count;
    double mean[16] = {0};

    ofstream fout("stockstuff.csv");
    // save the initial values

    for (int i = 0; i < 1000; i++)
    {
        // initialize Random number generator
        default_random_engine generator;
        generator.seed(rand() % 1000);                  // set the seed
        normal_distribution<double> distribution(0, 1); // mean 0, var 1
        S[0][i] = 77.84;
        count = 1;
        fout << "\n"
             << i + 1 << "," << S[0][i] << ",";
        while (count <= 15) // make prediction for 15 days
        {
            double epsilon = distribution(generator);
            S[count][i] = S[count - 1][i] * exp((mu - sigma * sigma / 2) * dt + sigma * epsilon * sqrt(dt));
            fout << S[count][i] << ",";

            mean[count] = mean[count] + S[count][i] / 1000;

            count++;
        }
    }
    fout.close();

    for (int j = 1; j <= 15; j++)
    {
        for (int i = 0; i < 1000; i++)
        {
            var = pow((S[j][i] - mean[j]), 2);

            aa += var;
        }
        var_cal[j] = aa / 1000;
    }

    // 95% confidence interval

    ofstream fout1("stockmean.csv");

    double final_result1[16], final_result2[16];
    for (int j = 1; j <= 15; j++)
    {
        final_result1[j] = mean[j] - 1.96 * (var_cal[j] / sqrt(1000));
        fout1 << final_result1[j] << ",";
        final_result2[j] = mean[j] + 1.96 * (var_cal[j] / sqrt(1000));
    }
    fout1 << "\n";
    for (count = 1; count <= 15; count++)
    {
        fout1 << mean[count] << ",";
    }
    fout1 << "\n";
    for (count = 1; count <= 15; count++)
    {
        fout1 << final_result2[count] << ",";
    }

    fout1.close();
    return 0;
}
