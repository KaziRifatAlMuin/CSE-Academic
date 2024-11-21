#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int M = 1e5;

int N;
double eps = 1e-6;

double a[M];
int n;
int mark[2 * M + 2];

// f(x) = a0x^n + a1x^n-1 + .... + an-1x + an;

double f(double x){
    double ans = 0;
    for(int i = 0, p = n; i <= n; i++, p--){
        ans += (pow(x, p) * a[i]);
    }
    return ans;
}

void bisection(){
    ll st = clock();
    vector<double> roots;
    memset(mark, 0, sizeof(mark));

    double left = 0, right = 0;
    bool found = false;
    
    // Find initial interval [left, right] where the root lies
    for(int i = 0; i < N; i++){
        if(f(i) * f(i + 1) <= 0 && !mark[i + N]){
            left = i;
            right = i + 1;
            mark[i + N] = true;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No root found in the interval.\n";
        return;
    }
    
    double x0 = (left + right) / 2;
    double dx = fabs(right - left);
    int op = 0;
    
    while(fabs(f(x0)) > eps && op < 10000){ 
        cout << fixed << setprecision(6);
        // cout << op + 1 << " : ";
        // cout << left << " " ;
        // cout << right << " " ;
        // cout << x0 << " " ;
        // cout << f(x0) << " ";
        cout << dx << " ";
        cout << "\n";
        if(f(left) * f(x0) <= 0){
            right = x0;
        }
        else{
            left = x0;
        }
        double newX0 = (left + right) / 2;
        dx = fabs(x0 - newX0);
        x0 = newX0;
        op++;
    }
    
    roots.push_back(x0);
    
    cout << "Bisection Method:\n________________________________\n";
    cout << "Root = ";
    for(auto x : roots) cout << x << " ";
    cout << "\n[Iterations: " << op << "]\n";
    cout << "[Time: " << 1000000 * (clock() - st) / CLOCKS_PER_SEC << " us]\n";
    cout << "________________________________\n\n";
}

void falsePosition(){
    ll st = clock();
    vector<double> roots;
    memset(mark, 0, sizeof(mark));

    double left = 0, right = 0;
    bool found = false;
    
    // Find initial interval [left, right] where the root lies
    for(int i = 0; i < N; i++){
        if(f(i) * f(i + 1) <= 0 && !mark[i + N]){
            left = i;
            right = i + 1;
            mark[i + N] = true;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No root found in the interval.\n";
        return;
    }
    
    double x0 = (left * f(right) - right * f(left)) / (f(right) - f(left));
    double dx = fabs(right - left);
    int op = 0;
    
    while(fabs(f(x0)) > eps && op < 10000){
        cout << fixed << setprecision(6);
        // cout << op + 1 << " : ";
        // cout << left << " " ;
        // cout << right << " " ;
        // cout << x0 << " " ;
        // cout << f(x0) << " ";
        // cout << dx << " ";
        cout << "\n";
        if(f(left) * f(x0) <= 0){
            right = x0;
        }
        else{
            left = x0;
        }
        double newX0 = (left * f(right) - right * f(left)) / (f(right) - f(left));
        dx = fabs(x0 - newX0);
        x0 = newX0;
        op++;
    }
    
    roots.push_back(x0);
    
    cout << "False Position Method:\n________________________________\n";
    cout << "Root = ";
    for(auto x : roots) cout << x << " ";
    cout << "\n[Iterations: " << op << "]\n";
    cout << "[Time: " << 1000000 * (clock() - st) / CLOCKS_PER_SEC << " us]\n";
    cout << "________________________________\n\n";
}

void solve() {
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    
    // Estimate N
    N = sqrt(((a[1] / a[0]) * (a[1] / a[0])) - (2 * a[2] / a[0])) + 1;
    
    bisection();
    falsePosition();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time: " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
