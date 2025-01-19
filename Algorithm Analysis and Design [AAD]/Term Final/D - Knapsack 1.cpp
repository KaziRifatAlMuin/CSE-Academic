#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105, maxW = 1e5 + 5;

ll dp[N][maxW];
ll n, W;
vector <ll> p, w;

ll run(int i, int rem_w){
    if(i == n) return 0;
    if(dp[i][rem_w] != -1) return dp[i][rem_w];
    ll ans = run(i + 1, rem_w);
    if(rem_w - w[i] >= 0) ans = max(ans, p[i] + run(i + 1, rem_w - w[i]));
    return dp[i][rem_w] = ans;
}

void solve() {
    cin >> n >> W;
    p.resize(n); w.resize(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> w[i] >> p[i];
    cout << run(0, W) << "\n";
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
// https://atcoder.jp/contests/dp/tasks/dp_d