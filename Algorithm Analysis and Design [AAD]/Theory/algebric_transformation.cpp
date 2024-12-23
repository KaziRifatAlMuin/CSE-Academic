#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global variables for operation counts
ll denseHornerOps = 0, denseStraightOps = 0;
ll sparseStraightOps = 0, sparseHornerOps = 0;

// Function to compute x^n using exponentiation by squaring
ll Power(ll x, ll n, ll& ops) {
    ll result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
            ops++; // Multiplication when exponent is odd
        }
        x *= x; // Square the base
        n /= 2; // Halve the exponent
        ops += 2; // Multiplication and division
    }
    return result;
}

// Function 1: Dense Polynomial Evaluation using Horner's Rule
ll DenseHorner(const vector<ll>& Adense, ll x) {
    denseHornerOps = 0; // Reset operation counter
    int n = Adense.size() - 1; // Degree of the polynomial
    ll result = Adense[n];     // Start with the leading coefficient
    denseHornerOps++;          // Initial operation (assignment)

    for (int i = n - 1; i >= 0; i--) {
        result = result * x + Adense[i];
        denseHornerOps += 2; // One multiplication and one addition
    }
    return result;
}

// Function 2: Dense Polynomial Evaluation using Straightforward Method
ll DenseStraightEval(const vector<ll>& Adense, ll x) {
    denseStraightOps = 0; // Reset operation counter
    int n = Adense.size() - 1; // Degree of the polynomial
    ll result = 0;
    denseStraightOps++; // Initial assignment

    for (int i = 0; i <= n; i++) {
        ll power = Power(x, i, denseStraightOps); // Compute x^i efficiently
        result += Adense[i] * power;
        denseStraightOps += 2; // Multiplication and addition
    }
    return result;
}

// Function 3: Sparse Polynomial Evaluation using straightforward method
ll SparseStraightEval(const vector<pair<ll, ll>>& Asparse, ll x) {
    sparseStraightOps = 0; // Reset operation counter
    ll result = 0;
    sparseStraightOps++; // Initial assignment

    for (auto term : Asparse) {
        ll coefficient = term.first;
        ll exponent = term.second;
        ll power = Power(x, exponent, sparseStraightOps); // Compute x^exponent efficiently
        result += coefficient * power;
        sparseStraightOps += 2; // Multiplication and addition
    }
    return result;
}

// Function 4: Sparse Polynomial Evaluation using Horner's approach
ll SparseHornerEval(const vector<pair<ll, ll>>& Asparse, ll x) {
    sparseHornerOps = 0; // Reset operation counter
    ll result = 0, e_prev = 0;
    sparseHornerOps += 2; // Initial assignments

    for (int i = Asparse.size() - 1; i >= 0; i--) {
        ll coefficient = Asparse[i].first;
        ll exponent = Asparse[i].second;

        ll power = Power(x, exponent - e_prev, sparseHornerOps); // Power for the gap
        result = result * power + coefficient;
        sparseHornerOps += 2; // Multiplication and addition

        e_prev = exponent;
    }
    return result;
}

void solve() {
    // Dense Polynomial Example
    vector<ll> densePoly = {1, 2, 0, 1}; // 1 + 2x + 0x^2 + x^3
    ll x1 = 2;

    cout << "Dense Polynomial (Horner's Rule): " << DenseHorner(densePoly, x1)
         << " [Operations: " << denseHornerOps << "]\n";
    cout << "Dense Polynomial (Straightforward): " << DenseStraightEval(densePoly, x1)
         << " [Operations: " << denseStraightOps << "]\n";

    // Sparse Polynomial Example
    vector<pair<ll, ll>> sparsePoly = {{1, 0}, {1, 1000}}; // x^1000 + 1
    ll x2 = 1;

    cout << "Sparse Polynomial (Straightforward): " << SparseStraightEval(sparsePoly, x2)
         << " [Operations: " << sparseStraightOps << "]\n";
    cout << "Sparse Polynomial (Horner's Rule): " << SparseHornerEval(sparsePoly, x2)
         << " [Operations: " << sparseHornerOps << "]\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, st = clock();
    while (t--) {
        solve();
    }
    return 0;
}
