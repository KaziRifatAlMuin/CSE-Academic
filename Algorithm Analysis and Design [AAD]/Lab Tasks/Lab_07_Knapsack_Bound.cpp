#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 7;

int n, m, inf = 1e9 + 7;
vector <int> p, w;;
vector <pair<int,int>> items;

bool compare (pair <int, int> a, pair <int, int> b){
    double r1 = 1.0 * a.first / a.second;
    double r2 = 1.0 * b.first / b.second;
    return r1 > r2;
}

int Bound(int cp, int cw, int k){
    // k = index of the last removed item
    int b = cp, c = cw;
    for(int i = k + 1; i < n; i++){
        c += w[i];
        if(c < m) b += p[i];
        else return b + (1 - (c/m) / w[i]) * p[i];
    }
    return b;
}

int Ubound(int cp, int cw, int k){
    // k = index of the last removed item
    int b = cp, c = cw;
    for(int i = k + 1; i < n; i++){
        if(c + w[i] <= m){
            c += w[i];
            b -= p[i];
        }
    }
    return b;
}

int main() {
    cin >> n >> m;
    vector <int> ans(n);
    p.resize(n), w.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++){
        items.push_back({p[i], w[i]});
    }
    sort(items.begin(), items.end(), compare);
    for(auto x : items){
        // cout << x.first << " " << x.second << "\n";
    }
    int cp = 0, cw = 0, k = -1;
    for(int i = 0; i < n; i++){
        int upper = Ubound(cp, cw, k);
        int profit = Bound(cp, cw, k);
        int take_u = upper;
        int take_p = profit;
        int not_take_u = cp;
        int not_take_p = cw;
        if(take_p < not_take_p){
            cp = take_u;
            cw = take_p;
            ans[i] = 1;
        }
        else{
            k = i;
        }
    }
    cout << abs(cp) << "\n";
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

/*

8 110
11 21 31 33 43 53 55 65
1 11 21 23 33 43 45 55


*/