#include <iostream>
using namespace std;

int main()
{
  const int MAX_SIZE = 10;
  int count;
  float dataX[MAX_SIZE], dataY[MAX_SIZE], factor[MAX_SIZE], value, sum = 0;

  cout << "Enter the total count of values to be entered: ";
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cout << "x[" << i << "]: ";
    cin >> dataX[i];
    cout << "y[" << i << "]: ";
    cin >> dataY[i];
  }

  cout << "Enter the value of x for which it is to be interpolated: ";
  cin >> value;

  for (int i = 0; i < count; i++)
  {
    factor[i] = 1.0f;
    for (int j = 0; j < count; j++)
    {
      if (i != j)
      {
        factor[i] *= (value - dataX[j]) / (dataX[i] - dataX[j]);
      }
    }
  }

  for (int i = 0; i < count; i++)
  {
    sum += factor[i] * dataY[i];
  }

  cout << "The interpolated value is: " << sum;
  return 0;
}