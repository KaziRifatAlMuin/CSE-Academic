#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double LarrangeInterpolation(vector <double> x, vector <double> y, double new_x){
    int n = x.size();
    double ans = 0;
    for(int i = 0; i < n; i++){
        double fi = y[i], li = 1;
        for(int j = 0; j < n; j++){
            if(i != j) li *= ((new_x - x[j]) / (x[i] - x[j]));
        }
        ans += (fi * li);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector <double> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    double new_x = 2 * 12;
    double ans = LarrangeInterpolation(x, y, new_x);
    cout << "Weight of the baby at 2 years will be ";
    cout << ans << " kg or " << ans * 2.20462 << " lbs \n";

    return 0;
}

/*
4
2 3 5 6
4 6 7 10
*/