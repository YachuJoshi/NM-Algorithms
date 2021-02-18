#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using std::string;
using namespace std;

double functionX(float x)
{
    return (x * sin(x)) + cos(x);
}

string logFunctionX()
{
    return "(x * sin(x)) + cos(x)";
}

bool isValid(double a, double b)
{
    if (a * b > 0)
        return false;
    return true;
}

int main()
{
    double a, b, t, c;
    cout << "First Interval: ";
    cin >> a;
    cout << "Second Interval: ";
    cin >> b;
    cout << "Tolerance Error: ";
    cin >> t;
    cout << "The function defined is: " << logFunctionX() << endl;
    c = (a + b) / 2;

    if (!isValid(functionX(a), functionX(b)))
    {
        cout << "Invalid. No solution found.";
    }
    else
    {
        cout << "Valid" << endl;
        while (abs(b - a) >= t || abs(functionX(c)) >= t)
        {
            if ((functionX(c) * functionX(a)) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
            c = (a + b) / 2;
        }
        cout << "The root is: " << c;
    }
    return 0;
}
