#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x, float y)
{
  return x + y;
}

int main()
{
  float initialX, initialY, finalX, finalY, xValue, yValue, stepSize, n, k;
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
    k = stepSize * function(xValue, yValue);
    xValue += stepSize;
    yValue += k;
    cout << xValue << "\t" << setprecision(5) << yValue << endl;
  }

  return 0;
}