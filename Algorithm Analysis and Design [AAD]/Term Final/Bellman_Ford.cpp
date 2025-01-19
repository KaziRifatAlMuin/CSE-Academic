#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

vector<pair<ll, ll>> G[N];
ll dist[N], parent[N];
ll n, m;

bool BellmanFord(ll start) {
    fill(dist, dist + n + 1, INF);
    fill(parent, parent + n + 1, -1);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto x : G[u]) {
                ll v = x.first;
                ll weight = x.second;
                if (dist[u] < INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    vector<ll> cycleNodes;
    for (int u = 0; u < n; u++) {
        for (auto x : G[u]) {
            ll v = x.first;
            ll weight = x.second;
            if (dist[u] < INF && dist[u] + weight < dist[v]) {
                cycleNodes.push_back(v);
            }
        }
    }

    if (cycleNodes.empty()) {
        return false;
    }

    set<ll> visited;
    for (ll node : cycleNodes) {
        visited.clear();
        ll current = node;
        for (int i = 0; i < n; i++) {
            current = parent[current];
        }
        ll cycleStart = current;
        vector<ll> cycle;
        cycleStart = parent[cycleStart];

        while (cycleStart != current){
            cycle.push_back(cycleStart);
            cycleStart = parent[cycleStart];
        }
        cycle.push_back(current);
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle detected: ";
        for (ll v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        G[i].clear();
    }

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    if(BellmanFord(0)){
        // Negative Cycle
    }
    else{
        for(int i = 0; i < n; i++){
            cout << "dist[" << i << "] = " << dist[i] << "\n";
        }
    }
    return 0;
}
