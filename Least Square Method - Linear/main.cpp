#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const int MAX_SIZE = 10;
  int count;
  float dataX[MAX_SIZE], dataY[MAX_SIZE], varA, varB, del, delOne, delTwo;
  float sumX = 0, sumY = 0, sumXSqr = 0, sumXY = 0;

  cout << "Enter no. of data: ";
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cout << "x[" << i << "]: ";
    cin >> dataX[i];
    cout << "y[" << i << "]: ";
    cin >> dataY[i];

    sumX += dataX[i];
    sumY += dataY[i];
    sumXY += dataX[i] * dataY[i];
    sumXSqr += pow(dataX[i], 2);
  }

  del = (count * sumXSqr) - (sumX * sumX);
  delOne = (sumY * sumXSqr) - (sumX * sumXY);
  delTwo = (count * sumXY) - (sumX * sumY);

  varA = delOne / del;
  varB = delTwo / del;

  cout << "A: " << varA << " B: " << varB;
  cout << "The equation is: "
       << "y = " << varA << " + " << varB << "x";
  return 0;
}