#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const int MAX_SIZE = 10;
  int count;
  float dataX[MAX_SIZE], dataY[MAX_SIZE], modifiedY[MAX_SIZE], varA, varB, modifiedA, del, delOne, delTwo;
  float sumX = 0, sumModifiedY = 0, sumXSqr = 0, sumXY = 0;

  cout << "Enter no. of data: ";
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cout << "x[" << i << "]: ";
    cin >> dataX[i];
    cout << "y[" << i << "]: ";
    cin >> dataY[i];

    modifiedY[i] = log(dataY[i]);

    sumX += dataX[i];
    sumModifiedY += modifiedY[i];
    sumXY += dataX[i] * modifiedY[i];
    sumXSqr += pow(dataX[i], 2);
  }

  del = (count * sumXSqr) - (sumX * sumX);
  delOne = (sumModifiedY * sumXSqr) - (sumX * sumXY);
  delTwo = (count * sumXY) - (sumX * sumModifiedY);

  modifiedA = delOne / del;
  varA = exp(modifiedA);
  varB = delTwo / del;

  cout << "A: " << varA << " B: " << varB;
  return 0;
}