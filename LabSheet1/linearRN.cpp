#include <iostream>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

int main()
{

    int a, c, m, Z, nSample;
    float print;
    nSample = 1000; // no. of random numbers
    Z = 2534;       // seed

    a = 50, c = 2, m = 53;

    ofstream fout("linearRN.csv");

    for (int i = 0; i < nSample; i++)
    {
        Z = (a * Z + c) % 52;
        print = Z;
        fout << print * 100 / 52 << "\n";
        // cout << Z;
    }

    fout.close();
    return 0;
}