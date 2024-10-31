#include<bits/stdc++.h>
using namespace std;

// Function for the differential equation
double f(double x, double y) {
    return (2 * x + 3 * y);
}

// Function to calculate the exact value
double exactvalue(double x, double y0) {
    double C = y0 + 2.0 / 9.0;
    return -2.0 / 9.0 * (3 * x + 1) + C * exp(3 * x);
}

// Function to perform Runge-Kutta method and generate the table with errors
double runge_kutta(double x0, double y0, double x1, double h) {
    int n = (x1 - x0) / h;
    double y = y0;
    double total_error = 0;
    double total_exact_y = 0;
    
    cout << "x       " << "RK_Y          " << "Exact_Y        " << "Error   " << endl;
    
    for (int i = 0; i <= n; i++) {
        // Calculate exact y value
        double exact_y = exactvalue(x0, y0);
        total_exact_y += exact_y;  // Sum of exact y values
        
        // Calculate error
        double error = abs(y - exact_y);
        total_error += error;
        
        // Output current values
        // cout << fixed << setprecision(6) << x0 << "\n";
        // cout << fixed << setprecision(6) << y << "\n"; 
        // cout << fixed << setprecision(6) << exact_y << "\n";
        cout << fixed << setprecision(6) << error << "\n";

        // Runge-Kutta steps
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h / 2, y + k1 / 2);
        double k3 = h * f(x0 + h / 2, y + k2 / 2);
        double k4 = h * f(x0 + h, y + k3);
        
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // Increment x
        x0 += h;
    }
    
    // Return the total error and total exact_y sum for percentage error calculation
    return (total_error / total_exact_y) * 100;
}

int main() {
    double x0 = 0.0;   // Initial x value
    double y0 = 1.0;   // Initial y value (y(x0) = y0)
    double x = 3.0;    // The x value at which we want to stop (end of interval)
    double h = 0.1;    // Step size

    // Calculate total error using Runge-Kutta method and return percentage error
    double percentage_error = runge_kutta(x0, y0, x, h);
    
    cout << "--------------------------------------" << endl;
    cout << "Average percentage error: " << percentage_error << "%" << endl;

    return 0;
}
