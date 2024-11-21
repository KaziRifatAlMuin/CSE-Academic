#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxIteration = 1000;
double tolerance = 1e-6;

// Function to evaluate polynomial at a given x using Horner's method
double f(const vector<double>& coef, double x) {
    double result = coef[0];
    int n = coef.size();
    for (int i = 1; i < n; ++i) {
        result = result * x + coef[i];
    }
    return result;
}

// Function to evaluate derivative of polynomial at a given x using Horner's method
double fPrime(const vector<double>& coef, double x) {
    int n = coef.size();
    if (n <= 1) return 0.0; // Derivative of constant is zero
    double result = coef[0] * (n - 1);
    for (int i = 1; i < n - 1; ++i) {
        result = result * x + coef[i] * (n - i - 1);
    }
    return result;
}

// Function to find intervals where the function changes sign or touches zero
vector<pair<double, double>> findSignChanges(const vector<double>& coef, double start, double end, double step) {
    vector<pair<double, double>> intervals;
    double x_prev = start;
    double f_prev = f(coef, x_prev);
    double x_curr, f_curr;

    for (x_curr = start + step; x_curr <= end; x_curr += step) {
        f_curr = f(coef, x_curr);
        if (f_prev * f_curr <= 0.0) {
            // Sign change detected or zero crossing
            intervals.push_back({x_prev, x_curr});
        }
        x_prev = x_curr;
        f_prev = f_curr;
    }
    return intervals;
}

// Function to remove duplicates and sort roots
void removeDuplicatesAndSort(vector<double>& roots, double tolerance) {
    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end(), [tolerance](double a, double b) {
        return fabs(a - b) <= tolerance;
    }), roots.end());
}

// Secant Method to find all real roots
vector<double> secantMethodAllRoots(const vector<double>& coef, int maxIter, double tolerance, double start, double end, double step) {
    vector<double> roots;
    vector<pair<double, double>> intervals = findSignChanges(coef, start, end, step);

    for (auto interval : intervals) {
        double x0 = interval.first;
        double x1 = interval.second;
        double f_x0 = f(coef, x0);
        double f_x1 = f(coef, x1);

        // Check if f(x0) is zero
        if (fabs(f_x0) <= tolerance) {
            // x0 is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - x0) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(x0);
            }
            continue; // Move to next interval
        }

        // Check if f(x1) is zero
        if (fabs(f_x1) <= tolerance) {
            // x1 is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - x1) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(x1);
            }
            continue; // Move to next interval
        }

        // Apply Secant Method
        double x_prev = x0;
        double x_curr = x1;
        double f_prev = f_x0;
        double f_curr = f_x1;

        int iteration = 0;
        while (iteration < maxIter) {
            if (fabs(f_curr - f_prev) < 1e-12) {
                // Denominator too small, skip this interval
                break;
            }
            double x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);
            double f_next = f(coef, x_next);

            if (fabs(f_next) <= tolerance || fabs(x_next - x_curr) <= tolerance) {
                // Root found
                bool is_new_root = true;
                for (double r : roots) {
                    if (fabs(r - x_next) <= tolerance) {
                        is_new_root = false;
                        break;
                    }
                }
                if (is_new_root) {
                    roots.push_back(x_next);
                }
                break;
            }

            x_prev = x_curr;
            f_prev = f_curr;
            x_curr = x_next;
            f_curr = f_next;

            iteration++;
        }
    }
    return roots;
}

// Newton-Raphson method to find all real roots
vector<double> newtonRaphsonAllRoots(const vector<double>& coef, int maxIter, double tolerance, double start, double end, double step) {
    vector<double> roots;
    vector<double> starting_points;

    // Generate starting points from start to end with step
    for (double x = start; x <= end; x += step) {
        starting_points.push_back(x);
    }

    for (double x0 : starting_points) {
        double x = x0;
        int iteration = 0;
        while (iteration < maxIter) {
            double f_x = f(coef, x);
            double f_prime_x = fPrime(coef, x);

            if (fabs(f_prime_x) < 1e-12) {
                // Derivative too small, skip this starting point
                break;
            }

            double xNew = x - f_x / f_prime_x;

            if (fabs(xNew - x) <= tolerance || fabs(f_x) <= tolerance) {
                // Root found
                bool is_new_root = true;
                for (double r : roots) {
                    if (fabs(r - xNew) <= tolerance) {
                        is_new_root = false;
                        break;
                    }
                }
                if (is_new_root) {
                    roots.push_back(xNew);
                }
                break;
            }

            x = xNew;
            iteration++;
        }
    }
    return roots;
}

// Bisection method to find all real roots
vector<double> biSectionAllRoots(const vector<double>& coef, int maxIter, double tolerance, double start, double end, double step) {
    vector<double> roots;
    vector<pair<double, double>> intervals = findSignChanges(coef, start, end, step);

    for (auto interval : intervals) {
        double a = interval.first;
        double b = interval.second;

        double f_a = f(coef, a);
        double f_b = f(coef, b);

        // Check if f(a) is zero
        if (fabs(f_a) <= tolerance) {
            // a is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - a) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(a);
            }
            continue; // Move to next interval
        }

        // Check if f(b) is zero
        if (fabs(f_b) <= tolerance) {
            // b is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - b) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(b);
            }
            continue; // Move to next interval
        }

        // Now check if f(a) and f(b) have opposite signs
        if (f_a * f_b > 0) {
            // No root in this interval
            continue;
        }

        double c, f_c;
        int iter;
        for (iter = 0; iter < maxIter; ++iter) {
            c = (a + b) / 2.0;
            f_c = f(coef, c);

            if (fabs(f_c) <= tolerance || fabs(b - a) <= tolerance) {
                // Root found
                bool is_new_root = true;
                for (double r : roots) {
                    if (fabs(r - c) <= tolerance) {
                        is_new_root = false;
                        break;
                    }
                }
                if (is_new_root) {
                    roots.push_back(c);
                }
                break;
            }

            if (f_a * f_c < 0) {
                b = c;
                f_b = f_c;
            } else {
                a = c;
                f_a = f_c;
            }
        }
    }
    return roots;
}

// False Position method to find all real roots
vector<double> falsePositionAllRoots(const vector<double>& coef, int maxIter, double tolerance, double start, double end, double step) {
    vector<double> roots;
    vector<pair<double, double>> intervals = findSignChanges(coef, start, end, step);

    for (auto interval : intervals) {
        double a = interval.first;
        double b = interval.second;
        double f_a = f(coef, a);
        double f_b = f(coef, b);

        // Check if f(a) is zero
        if (fabs(f_a) <= tolerance) {
            // a is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - a) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(a);
            }
            continue; // Move to next interval
        }

        // Check if f(b) is zero
        if (fabs(f_b) <= tolerance) {
            // b is a root
            bool is_new_root = true;
            for (double r : roots) {
                if (fabs(r - b) <= tolerance) {
                    is_new_root = false;
                    break;
                }
            }
            if (is_new_root) {
                roots.push_back(b);
            }
            continue; // Move to next interval
        }

        // Now check if f(a) and f(b) have opposite signs
        if (f_a * f_b > 0) {
            // No root in this interval
            continue;
        }

        double c, f_c;
        int iter;
        for (iter = 0; iter < maxIter; ++iter) {
            // Compute c using False Position formula
            c = (a * f_b - b * f_a) / (f_b - f_a);
            f_c = f(coef, c);

            if (fabs(f_c) <= tolerance || fabs(b - a) <= tolerance) {
                // Root found
                bool is_new_root = true;
                for (double r : roots) {
                    if (fabs(r - c) <= tolerance) {
                        is_new_root = false;
                        break;
                    }
                }
                if (is_new_root) {
                    roots.push_back(c);
                }
                break;
            }

            if (f_a * f_c < 0) {
                b = c;
                f_b = f_c;
            } else {
                a = c;
                f_a = f_c;
            }
        }
    }
    return roots;
}

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
            //cout << "Jacobi method converged in " << iter + 1 << " iterations." << endl;
            return xNew;
        }
        xOld = xNew;
    }

    cout << "Jacobi method did not converge within the maximum number of iterations." << endl;
    return xNew;
}

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
            //cout << "Gauss-Seidel method converged in " << iter + 1 << " iterations." << endl;
            return x;
        }
    }

    cout << "Gauss-Seidel method did not converge within the maximum number of iterations." << endl;
    return x;
}

// Gauss Elimination method
vector<double> gaussElimination(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Forward elimination
    for (int j = 0; j < n - 1; ++j) {
        // Partial pivoting
        int maxRow = j;
        for (int i = j + 1; i < n; ++i) {
            if (fabs(matrix[i][j]) > fabs(matrix[maxRow][j])) {
                maxRow = i;
            }
        }
        swap(matrix[j], matrix[maxRow]);

        for (int i = j + 1; i < n; ++i) {
            if (fabs(matrix[j][j]) < 1e-12) {
                cout << "Zero pivot encountered, no unique solution." << endl;
                return {};
            }
            double factor = matrix[i][j] / matrix[j][j];
            for (int k = j; k <= n; ++k) {
                matrix[i][k] -= factor * matrix[j][k];
            }
        }
    }

    // Back substitution
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        if (fabs(matrix[i][i]) < 1e-12) {
            cout << "Zero pivot encountered, no unique solution." << endl;
            return {};
        }
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    return solution;
}

// Gauss-Jordan Elimination method
vector<double> gaussJordanElimination(vector<vector<double>> matrix) {
    int n = matrix.size();

    for (int j = 0; j < n; ++j) {
        // Partial pivoting
        int maxRow = j;
        for (int i = j + 1; i < n; ++i) {
            if (fabs(matrix[i][j]) > fabs(matrix[maxRow][j])) {
                maxRow = i;
            }
        }
        swap(matrix[j], matrix[maxRow]);

        // Make pivot element 1
        double pivot = matrix[j][j];
        if (fabs(pivot) < 1e-12) {
            cout << "Zero pivot encountered, no unique solution." << endl;
            return {};
        }
        for (int k = j; k <= n; ++k) {
            matrix[j][k] /= pivot;
        }

        // Eliminate other entries in column
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                double factor = matrix[i][j];
                for (int k = j; k <= n; ++k) {
                    matrix[i][k] -= factor * matrix[j][k];
                }
            }
        }
    }

    // Extract solution
    vector<double> solution(n);
    for (int i = 0; i < n; ++i) {
        solution[i] = matrix[i][n];
    }

    return solution;
}

// LU Decomposition Function
bool luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    L.assign(n, vector<double>(n, 0.0));
    U.assign(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1.0; // Diagonal as 1
            else {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                if (fabs(U[i][i]) < 1e-12) {
                    // Singular matrix
                    return false;
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return true;
}

// Forward Substitution
vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }
    return y;
}

// Backward Substitution
vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = U.size();
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++)
            sum += U[i][j] * x[j];
        if (fabs(U[i][i]) < 1e-12) {
            // Singular matrix
            return {};
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
    return x;
}

// LU Factorization method
vector<double> luFactorization(const vector<vector<double>>& A, const vector<double>& b) {
    vector<vector<double>> L, U;
    if (!luDecomposition(A, L, U)) {
        cout << "LU Decomposition failed. Matrix may be singular." << endl;
        return {};
    }
    vector<double> y = forwardSubstitution(L, b);
    vector<double> x = backwardSubstitution(U, y);
    return x;
}

// Matrix Inversion using Gauss-Jordan Elimination
bool invertMatrix(const vector<vector<double>>& A, vector<vector<double>>& inverse) {
    int n = A.size();
    vector<vector<double>> augmentedMatrix(n, vector<double>(2 * n));

    // Initialize augmented matrix [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            augmentedMatrix[i][j] = A[i][j];
        for (int j = n; j < 2 * n; j++)
            augmentedMatrix[i][j] = (i == (j - n)) ? 1.0 : 0.0;
    }

    // Perform Gauss-Jordan elimination
    for (int j = 0; j < n; ++j) {
        // Partial pivoting
        int maxRow = j;
        for (int i = j + 1; i < n; ++i) {
            if (fabs(augmentedMatrix[i][j]) > fabs(augmentedMatrix[maxRow][j])) {
                maxRow = i;
            }
        }
        swap(augmentedMatrix[j], augmentedMatrix[maxRow]);

        // Make pivot element 1
        double pivot = augmentedMatrix[j][j];
        if (fabs(pivot) < 1e-12) {
            //cout << "Matrix is singular and cannot be inverted." << endl;
            return false;
        }
        for (int k = 0; k < 2 * n; ++k) {
            augmentedMatrix[j][k] /= pivot;
        }

        // Eliminate other entries in column
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                double factor = augmentedMatrix[i][j];
                for (int k = 0; k < 2 * n; ++k) {
                    augmentedMatrix[i][k] -= factor * augmentedMatrix[j][k];
                }
            }
        }
    }

    // Extract inverse matrix
    inverse.resize(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmentedMatrix[i][j + n];
        }
    }
    return true;
}

// Matrix Inversion Function
void matrixInversion() {
    int n;
    cout << "Enter the dimension n of the square matrix: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<double>> inverse;
    if (invertMatrix(A, inverse)) {
        cout << "\nThe inverse matrix is:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << fixed << setprecision(6) << setw(12) << inverse[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "The matrix is singular and cannot be inverted.\n";
    }
}

// Placeholder for Runge-Kutta Method (4th Order)
void rungeKuttaMethod() {
    cout << "Runge-Kutta Method (4th Order) is not yet implemented." << endl;
}

// Function to take input for linear equations
void takeInputForLinear(vector<vector<double>>& A, vector<double>& b) {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    A.resize(n, vector<double>(n));
    b.resize(n);

    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));

    // Display augmented matrix format
    cout << "\nEnter the augmented matrix coefficients row-wise (each row has " << n + 1 << " coefficients):\n";

    for (int i = 0; i < n; ++i) {
        // No extra print statements between inputs
        for (int j = 0; j < n + 1; ++j) {
            cin >> augmentedMatrix[i][j];
        }
    }

    // Separate A and b from augmented matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = augmentedMatrix[i][j];
        }
        b[i] = augmentedMatrix[i][n];
    }
}

// Function to take input for polynomials
void takeInputForPolynomial(vector<double>& coefficients) {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    coefficients.resize(degree + 1);
    cout << "Enter the coefficients (from highest degree to constant term):\n";
    for (int i = 0; i <= degree; ++i) {
        cout << "Coefficient of x^" << degree - i << ": ";
        cin >> coefficients[i];
    }
}

// Main Menu and Submenus
void mainMenu() {
    cout << "\n******** NUMERICAL METHODS CONSOLE APPLICATION ********\n";
    cout << "Select a category:\n";
    cout << "1. Linear Equations\n";
    cout << "2. Non-linear Equations\n";
    cout << "3. Differential Equations\n";
    cout << "4. Matrix Operations\n";
    cout << "0. Exit\n";  // Press 0 in the main menu to exit the program
    cout << "Enter your choice: ";
}

void linearMenu() {
    cout << "\nSelect a linear equation solving method:\n";
    cout << "1. Jacobi Method\n";
    cout << "2. Gauss-Seidel Method\n";
    cout << "3. Gauss Elimination\n";
    cout << "4. Gauss-Jordan Elimination\n";
    cout << "5. LU Factorization\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void nonlinearMenu() {
    cout << "\nSelect a non-linear equation solving method:\n";
    cout << "1. Bisection Method\n";
    cout << "2. False Position Method\n";
    cout << "3. Secant Method\n";
    cout << "4. Newton-Raphson Method\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void diffEqMenu() {
    cout << "\nSelect a differential equation solving method:\n";
    cout << "1. Runge-Kutta Method (4th Order)\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void matrixMenu() {
    cout << "\nSelect a matrix operation method:\n";
    cout << "1. Matrix Inversion\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

// Functions to handle solving based on user's choice
void solveLinear(int methodChoice) {
    vector<vector<double>> A;
    vector<double> b;

    takeInputForLinear(A, b);

    vector<double> solution;

    switch (methodChoice) {
        case 1: {  // Jacobi Method
            vector<double> initialGuess(b.size(), 0.0);
            solution = jacobiMethod(A, b, initialGuess);
            if (!solution.empty()) {
                cout << "\nJacobi Method Solution:\n";
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << solution[i] << endl;
                }
            }
            break;
        }
        case 2: {  // Gauss-Seidel Method
            vector<double> initialGuess(b.size(), 0.0);
            solution = gaussSeidelMethod(A, b, initialGuess);
            if (!solution.empty()) {
                cout << "\nGauss-Seidel Method Solution:\n";
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << solution[i] << endl;
                }
            }
            break;
        }
        case 3: {  // Gauss Elimination
            // Prepare augmented matrix
            int n = A.size();
            vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    augmentedMatrix[i][j] = A[i][j];
                }
                augmentedMatrix[i][n] = b[i];
            }

            solution = gaussElimination(augmentedMatrix);
            if (!solution.empty()) {
                cout << "\nGauss Elimination Solution:\n";
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << solution[i] << endl;
                }
            }
            break;
        }
        case 4: {  // Gauss-Jordan Elimination
            // Prepare augmented matrix
            int n = A.size();
            vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    augmentedMatrix[i][j] = A[i][j];
                }
                augmentedMatrix[i][n] = b[i];
            }

            solution = gaussJordanElimination(augmentedMatrix);
            if (!solution.empty()) {
                cout << "\nGauss-Jordan Elimination Solution:\n";
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << solution[i] << endl;
                }
            }
            break;
        }
        case 5: {  // LU Factorization
            solution = luFactorization(A, b);
            if (!solution.empty()) {
                cout << "\nLU Factorization Solution:\n";
                for (size_t i = 0; i < solution.size(); ++i) {
                    cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << solution[i] << endl;
                }
            }
            break;
        }
        default:
            cout << "Invalid method choice for linear equations.\n";
            break;
    }
}

void solveNonlinear(int methodChoice) {
    vector<double> coefficients;
    takeInputForPolynomial(coefficients);

    vector<double> roots;
    double start = -100.0;
    double end = 100.0;
    double step = 0.5;

    switch (methodChoice) {
        case 1: {  // Bisection Method
            roots = biSectionAllRoots(coefficients, maxIteration, tolerance, start, end, step);
            removeDuplicatesAndSort(roots, tolerance);

            cout << "\nRoots found by Bisection Method:\n";
            for (double root : roots) {
                cout << fixed << setprecision(6) << root << " ";
            }
            cout << endl;
            break;
        }
        case 2: {  // False Position Method
            roots = falsePositionAllRoots(coefficients, maxIteration, tolerance, start, end, step);
            removeDuplicatesAndSort(roots, tolerance);

            cout << "\nRoots found by False Position Method:\n";
            for (double root : roots) {
                cout << fixed << setprecision(6) << root << " ";
            }
            cout << endl;
            break;
        }
        case 3: {  // Secant Method
            roots = secantMethodAllRoots(coefficients, maxIteration, tolerance, start, end, step);
            removeDuplicatesAndSort(roots, tolerance);

            cout << "\nRoots found by Secant Method:\n";
            for (double root : roots) {
                cout << fixed << setprecision(6) << root << " ";
            }
            cout << endl;
            break;
        }
        case 4: {  // Newton-Raphson Method
            roots = newtonRaphsonAllRoots(coefficients, maxIteration, tolerance, start, end, step);
            removeDuplicatesAndSort(roots, tolerance);

            cout << "\nRoots found by Newton-Raphson Method:\n";
            for (double root : roots) {
                cout << fixed << setprecision(6) << root << " ";
            }
            cout << endl;
            break;
        }
        default:
            cout << "Invalid method choice for non-linear equations.\n";
            break;
    }
}

void solveDifferential(int methodChoice) {
    switch (methodChoice) {
        case 1: {
            rungeKuttaMethod();
            break;
        }
        default:
            cout << "Invalid method choice for differential equations.\n";
            break;
    }
}

void solveMatrix(int methodChoice) {
    switch (methodChoice) {
        case 1: {
            matrixInversion();
            break;
        }
        default:
            cout << "Invalid method choice for matrix operations.\n";
            break;
    }
}

// Main Function
int main() {
    int mainChoice, methodChoice;

    while (true) {
        mainMenu();
        cin >> mainChoice;

        if (mainChoice == 0) {
            cout << "Exiting the program.\n";
            break;
        }

        switch (mainChoice) {
            case 1:  // Linear Equations
                while (true) {
                    linearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveLinear(methodChoice);
                }
                break;
            case 2:  // Non-linear Equations
                while (true) {
                    nonlinearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveNonlinear(methodChoice);
                }
                break;
            case 3:  // Differential Equations
                while (true) {
                    diffEqMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveDifferential(methodChoice);
                }
                break;
            case 4:  // Matrix Operations
                while (true) {
                    matrixMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveMatrix(methodChoice);
                }
                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";
                break;
        }
    }

    return 0;
}