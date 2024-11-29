#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <pair<ll,ll>> G[N];
ll dist[N];

struct info{
    ll v, w;
    bool const operator < (const info node) const{
        return w > node.w;
    }
};

void dijkstra(int start){
    for(int i = 0; i < N; i++) dist[i] = 1e17;
    dist[start] = 0;
    priority_queue <info> q;
    q.push({start, 0});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        for(auto x : G[cur.v]){
            ll v = x.first;
            ll w = x.second;
            if(dist[v] > cur.w + w){
                dist[v] = cur.w + w;
                q.push({v, dist[v]});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
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