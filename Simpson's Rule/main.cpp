#include <iostream>
#include <cmath>

using namespace std;

float fX(float x)
{
  return (pow(x, 3) + 1);
}

int main()
{
  const int MAX_SIZE = 20;
  float lowerBound, upperBound, stripSize, xValue[MAX_SIZE], sum = 0;
  int numOfStrips, factor;

  cout << "Enter lower bound: ";
  cin >> lowerBound;

  cout << "Enter upper bound: ";
  cin >> upperBound;

  while (true)
  {
    cout << "Enter num of strips: ";
    cin >> numOfStrips;

    if (numOfStrips % 3 != 0)
    {
      cout << "Num of strips must be a multiple of 3. Try again." << endl;
    }
    else
    {
      break;
    }
  }

  stripSize = (upperBound - lowerBound) / numOfStrips;
  sum += fX(lowerBound) + fX(upperBound);

  for (int i = 1; i <= numOfStrips - 1; i++)
  {
    if (i % 3 == 0)
    {
      factor = 2;
    }
    else
    {
      factor = 3;
    }
    xValue[i] = lowerBound + i * stripSize;
    sum += factor * fX(xValue[i]);
  }

  sum *= (3 * stripSize) / 8;

  cout << "The sum is: " << sum;
  return 0;
}