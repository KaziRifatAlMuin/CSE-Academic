#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const int INF = 1e9 + 7;
vector <pair<int,int>> edges;
vector <int> GG[N];
int G[N][N];
int n, m;
int dist[N];
bool vis[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        for(int j = 1; j <= n; j++){
            G[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
        GG[u].push_back(v);
        edges.push_back({u, v});
    }
    int source, destination;
    cin >> source >> destination;

    dist[source] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(auto e : edges){
            int u = e.first, v = e.second;
            if(G[u][v] == INF) dist[v] = INF;
            else if(dist[u] + G[u][v] < dist[v]){
                dist[v] = dist[u] + G[u][v];
            }
        }
    }

    set <int> neg;

    for(auto e : edges){
        int u = e.first, v = e.second;
        if(dist[u] + G[u][v] < dist[v]){
            if(G[u][v] < 0) neg.insert(u), cout << u << " ";;
            // cout << u << " ";
        }
    }

    for(auto x : neg){
        queue <int> q;
        int max_u, max_v, small = 0;
        q.push(x);
        if(vis[x]) continue;
        vis[x] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : GG[u]){
                //cout << v << "\n";
                cout << u << " " << v << "\n";
                if(G[u][v] < small){
                    max_u = u;
                    max_v = v;
                    small = G[u][v];
                }
                if(!vis[v]) q.push(v);
                vis[v] = true;
            }
        }
        G[max_u][max_v] = INF;
        cout << max_u << " " << max_v << "\n";
    }

    dist[source] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(auto e : edges){
            int u = e.first, v = e.second;
            if(G[u][v] == INF) dist[v] = INF;
            else if(dist[u] + G[u][v] < dist[v]){
                dist[v] = dist[u] + G[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << "dist["  << i << "] = " << dist[i] << "\n";
    }
    if(dist[destination] == INF){
        cout << "Unreachable\n";
    }
    else{
        cout << dist[destination] << "\n";
    }
    return 0;
}

/*

5 6
1 2 4
2 3 -2
3 4 2
4 2 -3
1 5 8
3 5 1
1 5

*/
