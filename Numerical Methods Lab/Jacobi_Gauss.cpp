#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;

double a[4][4];
double b[4];

void Jacobi_method() {
    int n = 20;
    vector <double> x(n+1), y(n+1), z(n+1), Ex(n+1), Ey(n+1), Ez(n+1);
    for(int i = 1; i <= n; i++){
        x[i] = (b[1] - a[1][2] * y[i-1] - a[1][3] * z[i-1]) / a[1][1];
        y[i] = (b[2] - a[2][1] * x[i-1] - a[2][3] * z[i-1]) / a[2][2];
        z[i] = (b[3] - a[3][2] * y[i-1] - a[3][1] * x[i-1]) / a[3][3];
        Ex[i] = abs(x[i] - x[i-1]);
        Ey[i] = abs(y[i] - y[i-1]);
        Ez[i] = abs(z[i] - z[i-1]);
    }
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << x[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << y[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << z[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ex[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ey[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ez[i] << "\n";
    cout << "\n\n\n";
}

void Gauss_Seidel_method() {
    int n = 20;
    vector <double> x(n+1), y(n+1), z(n+1), Ex(n+1), Ey(n+1), Ez(n+1);
    for(int i = 1; i <= n; i++){
        x[i] = (b[1] - a[1][2] * y[i-1] - a[1][3] * z[i-1]) / a[1][1];
        y[i] = (b[2] - a[2][1] * x[i] - a[2][3] * z[i-1]) / a[2][2];
        z[i] = (b[3] - a[3][2] * y[i] - a[3][1] * x[i]) / a[3][3];
        Ex[i] = abs(x[i] - x[i-1]);
        Ey[i] = abs(y[i] - y[i-1]);
        Ez[i] = abs(z[i] - z[i-1]);
    }
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << x[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << y[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << z[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ex[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ey[i] << "\n";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << fixed << setprecision(4) << Ez[i] << "\n";
    cout << "\n\n\n";
}

void solve() {
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    Jacobi_method();
    Gauss_Seidel_method();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}