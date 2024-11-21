#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int const N = 15;

vector<ld> gaussSeidelMethod(const vector<vector<ld>>& A, const vector<ld>& b)
{
    int maxIteration = 1000;
    int n = b.size();
    vector<ld> x(n, 0.0);
    vector<ld> xOld(n, 0.0);

    for (int iter = 0; iter < maxIteration; ++iter)
    {
        xOld = x;
        for (int i = 0; i < n; ++i)
        {
            ld sum = 0.0;
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
    }

    return x;
}

int main() {
    int n;
    cin >> n;
    vector <ld> xx(n), yy(n);
    vector <ld> v(n);
    
    for(int i = 0; i < n; i++) cin >> xx[i];
    for(int i = 0; i < n; i++) cin >> yy[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    // for(int i = 0; i < n; i++) {
    //     cout << xx[i] << " " << yy[i] << "\n";
    // }

    ld x = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, y = 0, yx = 0, yx2 = 0, yx3 = 0;

    for(int i = 0; i < n; i++){
        x += xx[i];
        y += yy[i];
        x2 += pow(xx[i], 2);
        x3 += pow(xx[i], 3);
        x4 += pow(xx[i], 4);
        x5 += pow(xx[i], 5);
        x6 += pow(xx[i], 6);
        yx += yy[i] * xx[i];
        yx2 += yy[i] * pow(xx[i], 2);
        yx3 += yy[i] * pow(xx[i], 3);
    }

    ld nn = n;

    vector<vector<ld>> m1 = {
        {nn, x, x2},
        {x, x2, x3},
        {x2, x3, x4}
    };
    vector <ld> b1 = {y, yx, yx2};

    vector<vector<ld>> m2 = {
        {nn, x, x2, x3},
        {x, x2, x3, x4},
        {x2, x3, x4, x5},
        {x3, x4, x5, x6}
    };
    
    vector <ld> b2 = {y, yx, yx2, yx3};

    vector <ld> s1 = gaussSeidelMethod(m1, b1);
    vector <ld> s2 = gaussSeidelMethod(m2, b2);

    // for(auto x : s1){
    //     cout << x << " ";
    // }
    // cout << "\n";

    // for(auto x : s2){
    //     cout << x << " ";
    // }
    // cout << "\n";

    ld avg1 = 0, avg2 = 0, t1 = 0, t2 = 0;

    cout << "Prediction 1 : \n";
    for(int i = 0; i < n; i++){
        ld it = xx[i];
        ld y = s1[0] + s1[1] * it + s1[2] * it * it;
        // cout << i + 1 << " : " << y << "\n";
        t1 += y;
        avg1 += abs(y - v[i]);
    }
    cout << "\nAverage Temperature: " << t1 / 12 << "\n";
    cout << "Mean Absolute Error: " << avg1 / 12 << "\n\n";

    cout << "\nPrediction 2 : \n";
    for(int i = 0; i < n; i++){
        ld it = xx[i];
        ld y = s2[0] + s2[1] * it + s2[2] * it * it + s2[3] * it * it * it;
        // cout << i + 1 << " : " << y << "\n";
        t2 += y;
        avg2 += abs(y - v[i]);
    }
    cout << "\nAverage Temperature: " << t2 / 12 << "\n";
    cout << "Mean Absolute Error: " << avg2 / 12 << "\n\n";


    return 0;
}

/* 
Input :
12
1 2 3 4 5 6 7 8 9 10 11 12

23.8 
26.6 
33.1 
35.3 
34.5 
34.1
32.5
32.2
32.2
31.3
29.3
27.1

27.1
31.3
33.0
36.7
35.7
35.0
33.1
32.5
32.1
32.1
30.0
25.3

*/