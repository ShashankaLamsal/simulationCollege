#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include <stdlib.h>

using namespace std;

int main()
{

    int nSample;
    float print;
    nSample = 1000; // no. of random numbers
                    // seed

    ofstream fout("randCpp.csv");

    for (int i = 0; i < nSample; i++)
    {
        fout << (rand() % 100) << "\n";
        // cout << Z;
    }

    fout.close();
    return 0;
}