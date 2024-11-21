// Knapsack - 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

void solve() {
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n), p(n);
    ll sumP = 0;

    for(int i = 0; i < n; i++){
        cin >> w[i] >> p[i];
        sumP += p[i];
    }

    // DP array: min weight to achieve profit `j`
    vector<ll> dp(sumP + 1, inf);
    dp[0] = 0; // Minimum weight for profit 0 is 0

    for(int i = 0; i < n; i++){
        for(ll j = sumP; j >= p[i]; j--){
            dp[j] = min(dp[j], dp[j - p[i]] + w[i]);
        }
    }

    // Find the maximum profit within weight limit
    ll ans = 0;
    for(ll j = sumP; j >= 0; j--){
        if(dp[j] <= W){
            ans = j;
            break;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
