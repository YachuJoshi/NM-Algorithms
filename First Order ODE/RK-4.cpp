#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x, float y)
{
  return 2 * y / x;
}

int main()
{
  float initialX, initialY, finalX, xValue, yValue, stepSize, n, k, k1, k2, k3, k4;
  cout << "Enter inital x, y: ";
  cin >> initialX >> initialY;
  cout << "Enter step size: ";
  cin >> stepSize;
  cout << "Enter value of x for which y is to be determined: ";
  cin >> finalX;

  n = (finalX - initialX) / stepSize;
  xValue = initialX;
  yValue = initialY;

  cout << "X\t"
       << "Y" << endl;

  for (int i = 0; i < n; i++)
  {
    k1 = stepSize * function(xValue, yValue);
    k2 = stepSize * function(xValue + (stepSize / 2), yValue + (k1 / 2));
    k3 = stepSize * function(xValue + (stepSize / 2), yValue + (k2 / 2));
    k4 = stepSize * function(xValue + stepSize, yValue + k3);
    k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    xValue += stepSize;
    yValue += k;

    cout << xValue << "\t" << yValue << endl;
  }

  return 0;
}