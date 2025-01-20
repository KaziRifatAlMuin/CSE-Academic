#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
ll inf = -1e17 + 7;

ll dp[N];

int main()
{
    ll n;
    cin >> n;
    vector <ll> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        dp[i] = v[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], v[j] + dp[i - j]);
        }
    }
    cout << dp[n] << "\n";

    return 0;
}

/*
4
-1 -2 2 -3
*/
