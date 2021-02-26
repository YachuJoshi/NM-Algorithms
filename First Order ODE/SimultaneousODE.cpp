#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float functionY(float x, float y, float z)
{
  return x + y + z;
}

float functionZ(float x, float y, float z)
{
  return 1 + y + z;
}

int main()
{
  float initialX, initialY, initalZ, finalX, xValue, yValue, stepSize, n, k, k1, k2, k3, k4, zValue, l, l1, l2, l3, l4;
  cout << "Enter inital x, y, z: ";
  cin >> initialX >> initialY >> initalZ;
  cout << "Enter step size: ";
  cin >> stepSize;
  cout << "Enter value of x for which y is to be determined: ";
  cin >> finalX;

  n = (finalX - initialX) / stepSize;
  xValue = initialX;
  yValue = initialY;
  zValue = initalZ;

  cout << "X\t"
       << "Y\t"
       << "Z" << endl;

  for (int i = 0; i < n; i++)
  {
    k1 = stepSize * functionY(xValue, yValue, zValue);
    l1 = stepSize * functionZ(xValue, yValue, zValue);

    k2 = stepSize * functionY(xValue + (stepSize / 2), yValue + (k1 / 2), zValue + (l1 / 2));
    l2 = stepSize * functionZ(xValue + (stepSize / 2), yValue + (k1 / 2), zValue + (l1 / 2));

    k3 = stepSize * functionY(xValue + (stepSize / 2), yValue + (k2 / 2), zValue + (l2 / 2));
    l3 = stepSize * functionZ(xValue + (stepSize / 2), yValue + (k2 / 2), zValue + (l2 / 2));

    k4 = stepSize * functionY(xValue + stepSize, yValue + k3, zValue + l3);
    l4 = stepSize * functionZ(xValue + stepSize, yValue + k3, zValue + l3);

    k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    l = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    xValue += stepSize;
    yValue += k;
    zValue += l;

    cout << xValue << "\t" << yValue << "\t" << zValue << endl;
  }

  return 0;
}