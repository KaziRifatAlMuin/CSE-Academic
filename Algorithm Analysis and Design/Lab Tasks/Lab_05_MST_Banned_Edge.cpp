#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1000;
int parent[N];
int n, m;

int Find(int x) {
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);
    if(root_x != root_y){
        parent[root_x] = root_y;
    }
}

ll Kruskal(vector <tuple<ll,ll,ll>> edges) {
    vector <tuple<ll,ll,ll>> MST;
    sort(edges.begin(), edges.end());
    ll sum = 0;
    for(auto [w, u, v] : edges){
        if(Find(u) != Find(v)){
            MST.push_back({w, u, v});
            Union(u, v);
            sum += w;
        }
        if(MST.size() == n - 1) break;
    }
    if(MST.size() == n - 1) return sum;
    else return -1;
}


int main()
{
    vector <tuple<ll,ll,ll>> edges, validEdges;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int k;
    cin >> k;
    vector <bool> allowed(m, true);
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        allowed[x] = false;
    }
    for(int i = 0; i < m; i++){
        if(allowed[i]){
            validEdges.push_back(edges[i]);
        }
    }
    for(int i = 0; i < N; i++) parent[i] = i;
    cout << Kruskal(validEdges) << "\n";
    return 0;
}

/*
6 9
1 2 2
1 3 3
2 3 1
3 4 4
4 5 5
3 5 6
2 5 8
5 6 6
4 6 7
3
0 2 3

*/

