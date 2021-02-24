#include <iostream>
#include <cmath>
using namespace std;

float determinant(float matrix[10][10], int n)
{
  float det = 0;
  float submatrix[10][10];
  if (n == 2)
    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
  else
  {
    for (int x = 0; x < n; x++)
    {
      int subi = 0;
      for (int i = 1; i < n; i++)
      {
        int subj = 0;
        for (int j = 0; j < n; j++)
        {
          if (j == x)
            continue;
          submatrix[subi][subj] = matrix[i][j];
          subj++;
        }
        subi++;
      }
      det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
    }
  }
  return det;
}

int main()
{
  const int MAX_SIZE = 10;
  const int MAX_DEGREE = 10;
  int n, degree;
  float dataX[MAX_SIZE], dataY[MAX_SIZE];
  float polyMatrix[MAX_SIZE][MAX_SIZE], coeff[MAX_DEGREE], polyResultMatrix[MAX_SIZE], delMatrix[MAX_DEGREE][MAX_SIZE][MAX_SIZE];
  float determinantMatrix[MAX_SIZE], del;

  while (true)
  {
    cout << "Enter degree of polynomial: ";
    cin >> degree;

    if (degree <= MAX_DEGREE)
    {
      break;
    }
    else
    {
      cout << "Degree too high. ";
    }
  }

  while (true)
  {
    cout << "Enter count of data: ";
    cin >> n;

    if (n <= MAX_SIZE)
    {
      break;
    }
    else
    {
      cout << "Data count too high. ";
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << "x[" << i << "]: ";
    cin >> dataX[i];
    cout << "y[" << i << "]: ";
    cin >> dataY[i];
  }

  for (int i = 0; i < n; i++)
  {
    polyResultMatrix[i] = 0;
    for (int j = 0; j < n; j++)
    {
      polyMatrix[i][j] = 0;
    }
  }

  // Populating polyMatrix
  for (int i = 0; i <= degree; i++)
  {
    for (int j = 0; j <= degree; j++)
    {
      if (i == 0 && j == 0)
      {
        polyMatrix[i][j] = n;
      }
      else
      {
        for (int k = 0; k < n; k++)
        {
          polyMatrix[i][j] += pow(dataX[k], i + j);
        }
      }
    }
  }

  // Populating PolyResultMatrix
  for (int i = 0; i <= degree; i++)
  {
    for (int j = 0; j < n; j++)
    {
      polyResultMatrix[i] += pow(dataX[j], i) * dataY[j];
    }
  }

  // Init delMatrix
  for (int i = 0; i <= degree; i++)
  {
    for (int j = 0; j <= degree; j++)
    {
      for (int k = 0; k <= degree; k++)
      {
        delMatrix[i][j][k] = polyMatrix[j][k];
      }
    }
  }

  // Populating deLMatrix
  for (int i = 0; i <= degree; i++)
  {
    for (int k = 0; k <= degree; k++)
    {
      delMatrix[i][k][i] = polyResultMatrix[k];
    }
  }

  del = determinant(polyMatrix, degree + 1);
  for (int i = 0; i <= degree; i++)
  {
    determinantMatrix[i] = determinant(delMatrix[i], degree + 1);
  }

  for (int i = 0; i <= degree; i++)
  {
    coeff[i] = determinantMatrix[i] / del;
    cout << "a[" << i << "]: " << coeff[i] << endl;
  }

  return 0;
}