#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI acos(-1.0)

double f(double x) {
    return sin(x);
}

int main()
{
    double x0 = 0, y0 = 0;
    double x = 4 * PI;
    double y = y0;
    double h = PI / 32;
    double k1, k2, k3, k4;

    //cout << fixed << setprecision(8) << "x: " << setw(10) << x0 << "\ty: " << setw(10) << y << "\n";
    cout << "(" << x0 << "," << y << ")," << "";
    while(x0 < x){
        k1 = h * f(x0);
        k2 = h * f(x0 + 0.5 * h);
        k3 = h * f(x0 + 0.5 * h);
        k4 = h * f(x0 + h);

        y += (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 += h;
        if(abs(y) <= 1e-8) y = 0;
        //cout << fixed << setprecision(8) << "x: " << setw(10) << x0 << "\ty: " << setw(10) << y << "\n";
        cout << "(" << x0 << "," << y << ")," << "";
    }
    return 0;
}
