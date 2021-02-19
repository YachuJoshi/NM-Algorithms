#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE 10

using namespace std;

float getLargestAbsolute(float arr[], int n)
{
    float maxVal = abs(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i]) > abs(maxVal))
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main()
{
    int n, countVar = 0;
    const int MAX_ITR = 100;
    float tolErr = 0.0005f, A[MAX_SIZE][MAX_SIZE], X[MAX_SIZE], Z[MAX_SIZE], D[MAX_SIZE], lambda, maxDiff, normalizeFactor = 0;

    // Input
    while (true)
    {
        cout << "Enter order of square matrix: ";
        cin >> n;
        if (n <= 10)
        {
            break;
        }
        else
        {
            cout << "Too high! Try something lesser." << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Initialize
    for (int i = 0; i < n; i++)
    {
        X[i] = 1;
    }

    while (true)
    {
        // Increament count
        countVar++;

        // Compute Z
        for (int i = 0; i < n; i++)
        {
            Z[i] = 0;
            for (int j = 0; j < n; j++)
            {
                Z[i] += A[i][j] * X[j];
            }
        }

        // Compute largest absolute from Z to get lambda
        lambda = getLargestAbsolute(Z, n);

        // Scale Z by lambda
        for (int i = 0; i < n; i++)
        {
            Z[i] = Z[i] / lambda;
        }

        // Compute error between Z and X
        for (int i = 0; i < n; i++)
        {
            D[i] = abs(Z[i] - X[i]);
        }

        // Replace X by Z
        for (int i = 0; i < n; i++)
        {
            X[i] = Z[i];
        }

        // Compute largest error
        maxDiff = getLargestAbsolute(D, n);

        // Break condition
        if (countVar > MAX_ITR || maxDiff < tolErr)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        normalizeFactor += pow(X[i], 2);
    }

    for (int i = 0; i < n; i++)
    {
        X[i] = X[i] / pow(normalizeFactor, 0.5);
    }

    cout << "Eigen Vector in Normal Form is: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "]: " << setprecision(5) << X[i] << endl;
    }

    cout << "Dominant Eigen Value is: " << setprecision(3) << lambda;
    return 0;
}
