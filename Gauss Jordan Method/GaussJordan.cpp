#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of unknowns: ";
    cin >> n;
    float factor;
    float *x = new float[n];

    float **ptr = new float *[n];
    for (int i = 0; i < n; ++i)
    {
        ptr[i] = new float[n + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "Enter coefficient for a[" << i << "][" << j << "]: ";
            cin >> *(*(ptr + i) + j);
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != j)
            {
                factor = *(*(ptr + i) + j) / *(*(ptr + j) + j);
                for (int k = 0; k <= n; k++)
                {
                    *(*(ptr + i) + k) -= factor * *(*(ptr + j) + k);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        *(x + i) = *(*(ptr + i) + n) / *(*(ptr + i) + i);
        cout << "x[" << i << "]: " << *(x + i) << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    delete[] x;
    return 0;
}
