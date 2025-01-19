#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> ans;

bool place(vector <int> &x, int row, int col) {
    for(int j = 0; j < row; j++){
        if(x[j] == col || abs(x[j] - col) == abs(row - j)) return false;
    }
    return true;
}

void NQueens(vector <int> &x, int row, int n) {
    for(int col = 0; col < n; col++){
        if(place(x, row, col)){
            x[row] = col;
            if(row == n - 1) ans.push_back(x);
            else NQueens(x, row + 1, n);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> x(n);
    NQueens(x, 0, n);
    cout << ans.size() << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/CodeChef-NQNS1