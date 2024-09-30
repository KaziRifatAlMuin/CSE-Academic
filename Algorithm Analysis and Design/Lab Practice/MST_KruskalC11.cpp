#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 10000;
int parent[N];
int n, m;

// Find function with path compression
int Find(int x) {
    if (parent[x] != x) 
        parent[x] = Find(parent[x]);
    return parent[x];
}

// Union function for union-find
void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

// Kruskal's algorithm to find MST
vector<tuple<ll, ll, ll>> Kruskal(vector<tuple<ll, ll, ll>>& edges) {
    vector<tuple<ll, ll, ll>> MST;
    sort(edges.begin(), edges.end());  // Sort edges by weight
    
    for (size_t i = 0; i < edges.size(); i++) {
        ll w, u, v;
        tie(w, u, v) = edges[i];  // Unpacking tuple
        if (Find(u) != Find(v)) {
            MST.push_back(edges[i]);
            Union(u, v);
        }
        if (MST.size() == n - 1) 
            break;  // Stop if MST has n-1 edges
    }
    return MST;
}

// Solve function for each test case
void solve() {
    vector<tuple<ll, ll, ll>> edges, MST;
    cin >> n >> m;

    // Reading edges
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(w, u, v));  // Using make_tuple instead of tuple constructor
    }

    // Initialize disjoint set (parent array)
    for (int i = 0; i < N; i++) 
        parent[i] = i;

    MST = Kruskal(edges);
    
    // Print edges of MST
    for (size_t i = 0; i < MST.size(); i++) {
        ll w, u, v;
        tie(w, u, v) = MST[i];  // Unpacking tuple
        cout << u << " " << v << " " << w << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // Uncomment the next line if you want to read multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
