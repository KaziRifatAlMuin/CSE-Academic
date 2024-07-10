#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

vector <pair <ll, ll>> G[N];
ll dist[N], pre[N];

struct info{
    ll v, w;
    bool operator < (const info &p) const{
        return w > p.w;
    }
};

void Dijkstra(ll u){
    for(ll i = 0; i < N; i++) dist[i] = INF;
    priority_queue <info> q;
    pre[u] = -1, dist[u] = 0;
    q.push({u, dist[u]});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        for(auto x : G[cur.v]){
            if(cur.w + x.second < dist[x.first]){
                dist[x.first] = cur.w + x.second;
                pre[x.first] = cur.v;
                q.push({x.first, dist[x.first]});
            }
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    Dijkstra(1);
    vector <ll> path;
    path.push_back(n);
    ll cur = n;
    if(dist[n] == INF){
        cout << -1 << "\n";
        return;
    }
    while(cur != 1){
        path.push_back(pre[cur]);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << " ";
    cout << "\n" << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}