#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxIteration = 1000;
double tolerance = 1e-6;

// Jacobi Method Function
vector<double> jacobiMethod(const vector<vector<double>>& A, const vector<double>& b, const vector<double>& initialGuess = {}) {
    int n = b.size();
    vector<double> xOld(n, 0.0);
    if (!initialGuess.empty()) {
        xOld = initialGuess;
    }
    vector<double> xNew(n, 0.0);
    vector<double> errors(n, 0.0);

    for (int iter = 0; iter < maxIteration; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * xOld[j];
                }
            }
            if (fabs(A[i][i]) < 1e-12) {
                cerr << "Zero diagonal element encountered at row " << i + 1 << endl;
                return {};
            }
            xNew[i] = (b[i] - sigma) / A[i][i];
            errors[i] = fabs(xNew[i] - xOld[i]);
        }

        // Check for convergence
        double maxError = *max_element(errors.begin(), errors.end());
        if (maxError < tolerance) {
            cout << "Jacobi method converged in " << iter + 1 << " iterations." << endl;
            return xNew;
        }
        xOld = xNew;
    }

    cout << "Jacobi method did not converge within the maximum number of iterations." << endl;
    return xNew;
}

/*

4 1 -1 3
1 5 1 7
2 1 6 10

Jacobi Method Solution:
x[1] = 0.809917
x[2] = 0.991735
x[3] = 1.231405

*/

// Testing the Jacobi Method

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

    vector<double> initialGuess(n, 0.0);
    vector<double> jacobiSolution = jacobiMethod(A, b, initialGuess);
    cout << "\nJacobi Method Solution:" << endl;
    for (size_t i = 0; i < jacobiSolution.size(); ++i) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << jacobiSolution[i] << endl;
    }
}


int main() {
    takeInputforLinear();
    return 0;
}
