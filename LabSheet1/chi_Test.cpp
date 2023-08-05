#include <iostream>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    ifstream fin("randCpp.csv");

    int i;
    float f[100], bin = 10, j = 0, X = 0, Xk;
    float a, n = 1000, peak = 100, k = 5; // bin size 10, degree of freedom=9
    float temp;

    for (i = 0; i < k; i++)
    {
        f[i] = 0;
        while (fin)
        {
            fin >> a;
            if ((a > (j * bin)) && (a <= ((j + 1) * bin)))
            {

                f[i]++;
            }
        }
        fin.clear();
        fin.seekg(0, std::ios::beg);
        j++;
    }
    fin.close();
    for (i = 0; i < k; i++)
    {
        cout << f[i] << ",";
        if (f[i] > 100)
            X = pow(f[i] - 100, 2) + X;
        else
            X = pow(100 - f[i], 2) + X;
    }
    X = X * k / n;
    cout << endl
         << "Xcalc="
         << X << endl;

    // for 90% confidence, alpha=0.10
    float cr = 1.645; // critical value
    Xk = (k - 1) * (1 - (2 / (9 * (k - 1))) + (cr * sqrt(2 / (9 * (k - 1)))));
    cout << "Xcrit=" << Xk;

    return 0;
}
