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
  float initialX, initialY, finalX, xValue, yValue, stepSize, n, k, k1, k2;
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
    k2 = stepSize * function(xValue + stepSize, yValue + k1);
    k = (k1 + k2) / 2;
    xValue += stepSize;
    yValue += k;
    cout << xValue << "\t" << setprecision(5) << yValue << endl;
  }

  return 0;
}