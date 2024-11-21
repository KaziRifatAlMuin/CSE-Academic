#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double trapezoidal (vector <double> y, double h) {
    int n = y.size();
    double integral = y[0] + y[n-1];
    for(int i = 1; i < n - 1; i++){
        integral += (2 * y[i]);
    }
    return integral * h / 2;
}

double simpsonsOneThird (vector <double> y, double h) {
    int n = y.size();
    double integral = y[0] + y[n-1];
    for(int i = 1; i < n - 1; i++){
        integral += (i % 2 == 0) ? 2 * y[i] : 4 * y[i];
    }
    return integral * h / 3;
}

double simpsonsThreeEigth (vector <double> y, double h) {
    int n = y.size();
    double integral = y[0] + y[n-1];
    for(int i = 1; i < n - 1; i++){
        integral += (i % 3 == 0) ? 2 * y[i] : 3 * y[i];
    }
    return integral * 3 * h / 8;
}


int main() {
    vector <double> y = {1, 1.5, 2, 2.5, 3, 3.5, 4};
    double a = 0, b = 3;
    double h = (b - a) / y.size() - 1;

    cout << "Trapezoidal : " << trapezoidal(y, h) << "\n";
    cout << "SimpsonsOneThird : " << simpsonsOneThird(y, h) << "\n";
    cout << "SimpsonsThreeEigth : " << simpsonsThreeEigth(y, h) << "\n";

}
