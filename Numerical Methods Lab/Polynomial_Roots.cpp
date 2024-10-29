#include <bits/stdc++.h>
using namespace std;

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

// Function to find intervals where the function changes sign
vector<pair<double, double>> findSignChanges(const vector<double>& coef, double start, double end, double step) {
    vector<pair<double, double>> intervals;
    double x_prev = start;
    double f_prev = f(coef, x_prev);
    double x_curr, f_curr;

    for (x_curr = start + step; x_curr <= end; x_curr += step) {
        f_curr = f(coef, x_curr);
        if (f_prev * f_curr <= 0.0) {
            // Sign change detected
            intervals.push_back({x_prev, x_curr});
        }
        x_prev = x_curr;
        f_prev = f_curr;
    }
    return intervals;
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

int main() {
    vector<double> coef;
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    coef.resize(degree + 1);

    cout << "Enter the coefficients (highest degree first):" << endl;
    for (int i = 0; i <= degree; ++i) {
        cin >> coef[i];
    }

    int maxIter = 1000;
    double tolerance = 1e-6;
    double start = -100.0;
    double end = 100.0;
    double step = 0.5;

    vector<double> roots_bisect = biSectionAllRoots(coef, maxIter, tolerance, start, end, step);
    vector<double> roots_falsepos = falsePositionAllRoots(coef, maxIter, tolerance, start, end, step);
    vector<double> roots_newton = newtonRaphsonAllRoots(coef, maxIter, tolerance, start, end, step);

    // Remove duplicates and sort the roots
    auto removeDuplicatesAndSort = [tolerance](vector<double>& roots) {
        sort(roots.begin(), roots.end());
        roots.erase(unique(roots.begin(), roots.end(), [tolerance](double a, double b) {
            return fabs(a - b) <= tolerance;
        }), roots.end());
    };

    removeDuplicatesAndSort(roots_bisect);
    removeDuplicatesAndSort(roots_falsepos);
    removeDuplicatesAndSort(roots_newton);

    cout << "Bisection Method: ";
    for (double root : roots_bisect) {
        cout << root << " ";
    }
    cout << endl;

    cout << "False Position Method: ";
    for (double root : roots_falsepos) {
        cout << root << " ";
    }
    cout << endl;

    cout << "Newton-Raphson Method: ";
    for (double root : roots_newton) {
        cout << root << " ";
    }
    cout << endl;

    return 0;
}

/*
3
1 -6 11 -6




*/