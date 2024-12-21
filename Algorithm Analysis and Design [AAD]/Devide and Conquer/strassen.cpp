#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Generate a random integer between L and R
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll L, ll R) {
    if(L > R) swap(L,R);
    return L + rnd() % (R - L + 1);
}

// Print matrix (for debugging)
void prllMatrix(const vector<vector<ll>>& mat) {
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Standard O(n^3) matrix multiplication
vector<vector<ll>> multiplyStandard(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    ll n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            ll sum = 0;
            for(ll k = 0; k < n; k++){
                sum += (ll) A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

// Add two matrices
vector<vector<ll>> addMatrix(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    ll n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Subtract two matrices
vector<vector<ll>> subMatrix(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    ll n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

static const int CUTOFF = 64; 

// Strassen's multiplication (recursive) - with minimal cutoff addition
vector<vector<ll>> strassen(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    ll n = A.size();

    // ----------- HYBRID CUTOFF -----------
    // If matrix size <= CUTOFF, just do regular multiplication.
    if(n <= CUTOFF) {
        return multiplyStandard(A, B);
    }
    // --------------------------------------

    if(n == 1) {
        return {{ A[0][0] * B[0][0] }};
    }

    ll half = n / 2;
    vector<ll> halfzero(half, 0);

    // Submatrices
    vector<vector<ll>> A11(half, halfzero), A12(half, halfzero),
                       A21(half, halfzero), A22(half, halfzero),
                       B11(half, halfzero), B12(half, halfzero),
                       B21(half, halfzero), B22(half, halfzero);

    for(ll i = 0; i < half; i++){
        for(ll j = 0; j < half; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Seven products (M1..M7)
    auto M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    auto M2 = strassen(addMatrix(A21, A22), B11);
    auto M3 = strassen(A11, subMatrix(B12, B22));
    auto M4 = strassen(A22, subMatrix(B21, B11));
    auto M5 = strassen(addMatrix(A11, A12), B22);
    auto M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    auto M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combine results
    vector<vector<ll>> C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<ll>> C12 = addMatrix(M3, M5);
    vector<vector<ll>> C21 = addMatrix(M2, M4);
    vector<vector<ll>> C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    // Construct C
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for(ll i = 0; i < half; i++){
        for(ll j = 0; j < half; j++){
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

void solve() {
    vector<ll> sizes;
    ll a = 1;
    for(int i = 0; i < 10; i++){
        a <<= 1;
        sizes.push_back(a);
    }

    ofstream file1 ("StandardResult.txt");
    ofstream file2 ("StrassenResult.txt");

    for (auto &n : sizes) {
        cout << "Matrix size: " << n << " x " << n << "\n";

        // Generate random matrices A and B
        vector<vector<ll>> A(n, vector<ll>(n, 0));
        vector<vector<ll>> B(n, vector<ll>(n, 0));

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                A[i][j] = get_rand(1, 1e9);
                B[i][j] = get_rand(1, 1e9);
            }
        }

        // -- Standard multiplication --
        auto startStd = chrono::high_resolution_clock::now();
        auto C_std = multiplyStandard(A, B);
        auto endStd = chrono::high_resolution_clock::now();
        ll timeStd = chrono::duration_cast<chrono::microseconds>(endStd - startStd).count();

        // -- Strassen multiplication --
        auto startStrassen = chrono::high_resolution_clock::now();
        auto C_strassen = strassen(A, B);
        auto endStrassen = chrono::high_resolution_clock::now();
        ll timeStrassen = chrono::duration_cast<chrono::microseconds>(endStrassen - startStrassen).count();

        if(C_std != C_strassen){
            cout << "Multiplication Failed!\n";
            return;
        }

        cout << "Standard Multiplication Time  : " << timeStd << " microseconds\n";
        cout << "Strassen Multiplication Time : " << timeStrassen << " microseconds\n";
        cout << "--------------------------------------------------\n";

        

        if(file1.is_open() && file2.is_open()){
            file1 << timeStd << "\n";
            file2 << timeStrassen << "\n";
        }
        else cout << "Unable to open file";
    }
    file1.close();
    file2.close();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
