#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 10000;
int parent[N];
int n, m;

int Find(int x) {
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if(rootX != rootY){
        parent[rootX] = rootY;
    }
}

vector <tuple <ll,ll,ll>> Kruskal(vector <tuple <ll,ll,ll>> edges){
    vector <tuple <ll,ll,ll>> MST;
    sort(edges.begin(), edges.end());
    for(auto [w, u, v] : edges){
        if(Find(u) != Find(v)){
            MST.push_back({w, u, v});
            Union(u, v);
        }
        if(MST.size() == n - 1) break;
    }
    return MST;
}

void solve()
{
    vector <tuple <ll,ll,ll>> edges, MST;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    for(int i = 0; i < N; i++) parent[i] = i;
    MST = Kruskal(edges);
    for(auto [w, u, v] : MST){
        cout << u << " " << v << " " << w << "\n";
    }
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