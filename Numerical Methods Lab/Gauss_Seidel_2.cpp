#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxIteration = 1000;
double tolerance = 1e-6;

// Gauss-Seidel Method Function
vector<double> gaussSeidelMethod(const vector<vector<double>>& A, const vector<double>& b, const vector<double>& initialGuess = {}) {
    int n = b.size();
    vector<double> x(n, 0.0);
    if (!initialGuess.empty()) {
        x = initialGuess;
    }
    vector<double> xOld(n, 0.0);
    vector<double> errors(n, 0.0);

    for (int iter = 0; iter < maxIteration; ++iter) {
        xOld = x;
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            // Use the latest values of x for updating
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * x[j];
                }
            }
            if (fabs(A[i][i]) < 1e-12) {
                cerr << "Zero diagonal element encountered at row " << i + 1 << endl;
                return {};
            }
            x[i] = (b[i] - sigma) / A[i][i];
            errors[i] = fabs(x[i] - xOld[i]);
        }

        // Check for convergence
        double maxError = *max_element(errors.begin(), errors.end());
        if (maxError < tolerance) {
            cout << "Gauss-Seidel method converged in " << iter + 1 << " iterations." << endl;
            return x;
        }
    }

    cout << "Gauss-Seidel method did not converge within the maximum number of iterations." << endl;
    return x;
}

/*

Sample Input:
4 1 -1 3
1 5 1 7
2 1 6 10

Gauss-Seidel Method Solution:
x[1] = 0.809918
x[2] = 0.991735
x[3] = 1.231405

*/

void takeInputforLinear() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));

    // Display augmented matrix format
    cout << "\nThe augmented matrix format is as follows (each row has " << n + 1 << " coefficients):" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "|";
        for (int j = 1; j <= n; ++j) {
            cout << " a" << i << j;
        }
        cout << " | b" << i << " |" << endl;
    }
    cout << "\nEnter the augmented matrix coefficients:" << endl;

    for (int i = 0; i < n; ++i) {
        // No extra print statements between inputs
        for (int j = 0; j < n + 1; ++j) {
            cin >> augmentedMatrix[i][j];
        }
    }

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = augmentedMatrix[i][j];
        }
        b[i] = augmentedMatrix[i][n];
    }

    vector<double> initialGuess(n, 0.0); // Starting with zero vector
    // Uncomment the following lines to input a custom initial guess
    /*
    cout << "Enter the initial guess vector x0:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> initialGuess[i];
    }
    */

    vector<double> gaussSeidelSolution = gaussSeidelMethod(A, b, initialGuess);
    cout << "\nGauss-Seidel Method Solution:" << endl;
    for (size_t i = 0; i < gaussSeidelSolution.size(); ++i) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << gaussSeidelSolution[i] << endl;
    }
}

int main() {
    takeInputforLinear();
    return 0;
}
