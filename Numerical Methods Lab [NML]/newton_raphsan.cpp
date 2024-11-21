#include <bits/stdc++.h>
using namespace std;

int const W = 12;
int const N = 100;
int a[N];
int n;
#define eps 1e-6

// Function to calculate f(x)
double f(double x) {
    double ans = 0;
    for(int p = n, i = 0; i <= n; i++, p--) {
        double xx = pow(x, p);
        ans += (a[i] * xx);
    }
    return ans;
}

// Function to calculate f'(x), the derivative of f(x)
double df(double x) {
    double ans = 0;
    for(int p = n - 1, i = 0; i < n; i++, p--) {
        double xx = pow(x, p);
        ans += (a[i] * (p * xx));
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    double x = 10;  // Initial guess
    int iterations = 0;
    // cout << setw(W) << "f(x)" << " " << setw(W) << "f'(x)" << " " << setw(W) << "x" << "\n";
    while (true) {
        double fx = f(x);
        double dfx = df(x);

        // Check if derivative is zero to prevent division by zero
        if (fabs(dfx) < eps) {
            cout << "Derivative is too small, try a different initial guess.\n";
            break;
        }

        double x_new = x - fx / dfx;
        double dx = fabs(x_new - x);

        cout << fixed << setprecision(6) << x << "\n";
        // cout << fixed << setprecision(6) << fx << "\n";
        // cout << fixed << setprecision(6) << dfx << "\n";
        // cout << fixed << setprecision(6) << dx << "\n";
        
        // Print the current values
        // cout << fixed << setprecision(6) << setw(W) << fx << " " << setw(W) << dfx << " " << setw(W) << x << "\n";

        // Check for convergence
        if (fabs(x_new - x) < eps) {
            x = x_new;
            break;
        }


        x = x_new;
        iterations++;
        
        // Limit the number of iterations to prevent infinite loops
        if (iterations > 1000) {
            cout << "Too many iterations, the method may not be converging.\n";
            break;
        }
    }

    // cout << "______________________________________________________________________\n";
    // cout << "\nSolution : " << x << "\n";
    // cout << "______________________________________________________________________\n";
    return 0;
}
