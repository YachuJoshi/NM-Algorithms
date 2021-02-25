#include <iostream>
#include <cmath>

using namespace std;

float fX(float x)
{
  return 1 / (1 + pow(x, 2));
}

int main()
{
  const int MAX_SIZE = 20;
  float lowerLimit, higherLimit, xValue[MAX_SIZE], yValue[MAX_SIZE], stripSize, sum;
  int numOfStrips;

  cout << "Enter lower limit: ";
  cin >> lowerLimit;
  cout << "Enter higher limit: ";
  cin >> higherLimit;
  cout << "Enter num of strips: ";
  cin >> numOfStrips;

  stripSize = (higherLimit - lowerLimit) / numOfStrips;

  for (int i = 0; i <= numOfStrips; i++)
  {
    xValue[i] = lowerLimit + i * stripSize;
    yValue[i] = fX(xValue[i]);
  }

  sum = yValue[0] + yValue[numOfStrips];

  for (int i = 1; i <= numOfStrips - 1; i++)
  {
    sum += 2 * yValue[i];
  }

  sum *= stripSize / 2;

  cout << "Sum is: " << sum;
}