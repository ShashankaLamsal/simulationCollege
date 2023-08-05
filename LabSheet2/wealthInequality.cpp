#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    int N = 100, Y = 300;
    double wealth[N] = {100};
    double var = 25;

    double event, R;

    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 25.0);
    generator.seed(23415);

    // csv print
    ofstream fout("wealth.csv");

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < N; j++)
        {

            event = rand() % 2;
            R = distribution(generator);
            if (event != 1)
            {
                wealth[j] = wealth[j] + R;
            }
            else
            {
                wealth[j] = wealth[j] - R;
            }
            if (wealth[j] <= 0)
            {
                wealth[j] = 0;
            }

            fout << wealth[j] << ",";
        }
        fout << "\n";
    }

    fout.close();
    ofstream fout1("wealthFinalYear.csv");

    for (int i = 0; i < N; i++)
    {
        fout1 << wealth[i] << "\n";
    }

    fout1.close();
    return 0;
    return 0;
}
