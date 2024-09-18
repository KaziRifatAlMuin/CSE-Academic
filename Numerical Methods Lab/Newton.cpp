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

double d(double x){
    double ans = 0;
    for(int p = n - 1, i = 0; i < n; i++, p--){
        double xx = pow(x, p);
        ans += ((p+1) * a[i] * xx);
    }
    return ans;
}


 
int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
 
    int op = 100;
    double x0 = 1, x1;
    // cout << setw(W) << "f(x1)" << " " << setw(W) << "f(x2)" << " ";
    // cout << setw(W) << "x1" << " " << setw(W) << "x2" << " " << setw(W) << "x3" << "\n";
    while(fabs(f(x0)) > eps){
        x1 = x0 - (f(x0) / d(x0));
        x0 = x1;
    }
    cout << "______________________________________________________________________\n";
    cout << "\nSolution : " << x1 << "\n";
    cout << "______________________________________________________________________\n";
    return 0;
}