#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  const int SIZE = 10;
  float a[SIZE][SIZE], x[SIZE], fraction;
  int i, j, k, n;
  cout << "Enter number of unknowns: ";
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n + 1; j++)
    {
      cout << "Coefficient at a[" << i << "][" << j << "]: ";
      cin >> a[i][j];
    }
  }
  for (i = 1; i <= n - 1; i++)
  {
    if (a[i][i] == 0.0)
    {
      cout << "Mathematical Error!";
      exit(1);
    }
    for (j = i + 1; j <= n; j++)
    {
      fraction = a[j][i] / a[i][i];

      for (k = 1; k <= n + 1; k++)
      {
        a[j][k] -= fraction * a[i][k];
      }
    }
  }

  x[n] = a[n][n + 1] / a[n][n];

  for (i = n - 1; i >= 1; i--)
  {
    x[i] = a[i][n + 1];

    for (j = i + 1; j <= n; j++)
    {
      x[i] = x[i] - a[i][j] * x[j];
    }

    x[i] = x[i] / a[i][i];
  }

  cout << "\nSolution:" << endl;
  ;

  for (i = 1; i <= n; i++)
  {

    cout << "x[" << i << "]: " << x[i] << endl;
  }

  return 0;
}
