#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double f(double x){
    return 1.9765 + 0.5059 * x;
}


int main() {
    vector <double> x = {1,2,3,4,6,8};
    
    for(auto it : x){
        cout << f(it) << "\n";
    }
}
