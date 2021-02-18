#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

float fX(float *coeff, float x, int n)
{
    float sum = 0;
    sum += *(coeff + 0);
    for (int i = 1; i <= n; i++)
    {
        sum += *(coeff + i) * pow(x, i);
    }
    return sum;
}

float dfX(float *coeff, float x, int n)
{
    float sum = 0;
    sum += *(coeff + 1);
    for (int i = 2; i <= n; i++)
    {
        sum += *(coeff + i) * pow(x, i - 1) * i;
    }
    return sum;
}

int main()
{
    int n;
    float *coeff;
    float x0, x1;

    cout << "Enter degree of polynomial: ";
    cin >> n;
    coeff = (float *)malloc((n + 1) * sizeof(float));

    for (int i = 0; i <= n; i++)
    {
        cout << "Enter coefficients for a[" << i << "]: ";
        cin >> coeff[i];
    }

    cout << "Enter initial guess: ";
    cin >> x0;

    x1 = x0;

    do
    {
        x0 = x1;
        if (dfX(coeff, x0, n))
        {
            x1 = x0 - (fX(coeff, x0, n) / dfX(coeff, x0, n));
        }
        else
        {
            cout << "Error: dfX = 0" << endl;
            exit(1);
        }

    } while (x0 != x1);

    cout << "The root of the function is: " << x1;
    return 0;
}
