#include <bits/stdc++.h>
using namespace std;
int const W = 12;
int const N = 100;
int a[N];
int n;
#define eps 1e-6
 
// a0x^n + a1x^n-1 + .... + an = 0
 
double f(double x){
    double ans = 0;
    for(int p = n, i = 0; i<= n; i++, p--){
        double xx = pow(x, p);
        ans += (a[i] * xx);
    }
    return ans;
}
 
int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
 
    int op = 10;
    double x1 = 4, x2 = 2, x3;
    cout << setw(W) << "f(x1)" << " " << setw(W) << "f(x2)" << " ";
    cout << setw(W) << "x1" << " " << setw(W) << "x2" << " " << setw(W) << "x3" << "\n";
    while(fabs(x2 - x1) > eps){
        x3 = x2 - (f(x2) * (x2 -x1) / (f(x2) - f(x1)));
        cout << fixed << setprecision(6) << setw(W) << f(x1) << " " << setw(W) << f(x2) << " ";
        cout << setw(W) << x1 << " " << setw(W) << x2 << " " << setw(W) << x3 << "\n";
        x1 = x2;
        x2 = x3;
    }
    cout << "______________________________________________________________________\n";
    cout << "\nSolution : " << x1 << "\n";
    cout << "______________________________________________________________________\n";
    return 0;
}