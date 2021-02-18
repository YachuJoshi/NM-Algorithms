#include <iostream>
#include <cstdlib>
#include <cmath>

const int maxCount = 10;

using namespace std;

double fX(double x)
{
    return pow(x, 3) - 3 * pow(x, 2) + 2 * x - 2;
}

int main()
{
    double a, b, c, tolErr;
    int countVar = 0;
    cout << "Enter left interval: ";
    cin >> a;
    cout << "Enter right interval: ";
    cin >> b;
    cout << "Enter error tolerance: ";
    cin >> tolErr;

    while (1)
    {
        if (fX(b) - fX(a) != 0)
        {
            c = (a * fX(b) - b * fX(a)) / (fX(b) - fX(a));
        }
        else
        {
            cout << "Cannot find root of the equation.";
            exit(1);
        }

        if (abs(fX(c)) < tolErr)
            break;

        if (countVar >= maxCount)
        {
            cout << endl
                 << "Iteration Limit exceeded." << endl;
            cout << "Couldn't find root." << endl;
            exit(1);
        }

        a = b;
        b = c;
        countVar++;
    }

    cout << "The root of equation is: " << c << endl;
    return 0;
}
