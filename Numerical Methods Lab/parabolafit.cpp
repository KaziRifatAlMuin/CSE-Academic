#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double f(double x){
    return 1.42 - 1.07 * x + 0.55 * x * x;
}


int main() {
    vector <double> xx = {0,1,2,3,4};
    vector <double> yy = {1, 1.8, 1.3, 2.5, 6.3};
    double sumx = 0, sumy = 0, x2 = 0, x3 = 0, x4 = 0, xy = 0, x2y = 0;
    for(int i = 0; i < 5; i++){
        double x = xx[i], y = yy[i];
        sumx += x;
        sumy += y;
        x2 += x * x;
        x3 += x * x * x;
        x4 += x * x * x * x;
        xy += x * y;
        x2y += x * x * y;
    }
    cout << sumx << " " << sumy << " " << x2 << " " << x3 << " "; 
    cout << x4 << " " << xy << " " << x2y << "\n";
    for(auto it : xx){
        cout << f(it) << "\n";
    }
}
