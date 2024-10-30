#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 15;

vector <double> forward_dely, backward_dely;
double table[N][N];

void buildTable(vector <double> y){
    int n = y.size();
    for(int j = 0; j < n; j++) table[0][j] = y[j];
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            table[i][j] = table[i-1][j] - table[i-1][j-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << fixed << setprecision(6) << table[i][j] << " ";
            if(i == j) forward_dely.push_back(table[i][j]);
            if(j == n - 1) backward_dely.push_back(table[i][j]);
        }
        cout << "\n";
    }
    cout << "Backward del y : ";
    for(auto del : backward_dely){
        cout << del << " ";
    }
    cout << "\n";

    cout << "Forward del y : ";
    for(auto del : forward_dely){
        cout << del << " ";
    }
    cout << "\n";
}

double NewtonForward(vector <double> x, vector <double> y, double new_x){
    int n = x.size();
    double s = (new_x - x[0]) / (x[1] - x[0]);
    double ans = forward_dely[0], fact = 1, cur_s = s;
    for(int i = 1; i < n; i++){
        ans += (s * forward_dely[i] / fact);
        cur_s = cur_s * (s + i);
        fact = fact * (i + 1);
    }
    return ans;
}

double NewtonBackward(vector <double> x, vector <double> y, double new_x){
    int n = x.size();
    double s = (x[n-1] - new_x) / (x[1] - x[0]);
    double ans = backward_dely[0], fact = 1, cur_s = s;
    for(int i = 1; i < n; i++){
        ans += (s * backward_dely[i] / fact);
        cur_s = cur_s * (s + i);
        fact = fact * (i + 1);
    }
    return ans;
}

double NewtonInterpolation(vector <double> x, vector <double> y, double new_x){
    int n = x.size();
    double midx;
    if(n & 1) midx = x[n/2];
    else midx = (x[n/2] + x[n/2 - 1]) / 2;
    cout << "Forward : " << NewtonForward(x, y, new_x) << "\n";
    cout << "Backward : " << NewtonBackward(x, y, new_x) << "\n";
    if(new_x < midx) return NewtonForward(x, y, new_x);
    else return NewtonBackward(x, y, new_x);
}


int main() {
    int n;
    cin >> n;
    vector <double> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];
    double new_x = 25;

    buildTable(y);
    cout << NewtonInterpolation(x, y, new_x) << "\n";

    return 0;
}

/*
5
10 20 30 40 50
0.1736 0.3420 0.5000 0.6428 0.7660
*/