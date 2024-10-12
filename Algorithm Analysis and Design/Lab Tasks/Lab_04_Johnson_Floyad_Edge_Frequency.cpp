#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;
vector <pair <ll,ll>> G[N];
long long const inf = 1e17;
int n, m;
bool ok = true;
ll d[N][N], weight[N][N];
map <pair<ll,ll>, ll> cnt;

struct info{
    ll v, w;
    bool operator < (const info &p) const{
        return w > p.w;
    }
};

vector <ll> dijkstra(ll u, vector <ll> &pre){
    vector <ll> dist(n+1);
    for(int i = 0; i <= n; i++) dist[i] = inf;
    priority_queue <info> q;
    pre[u] = -1; dist[u] = 0;
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
    return dist;
}

vector <ll> BellmanFord(int s, bool * ok){
    vector <ll> dist(n+1);
    for(int i = 0; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(int u = 1; u <= n; u++){
            for(auto x : G[u]){
                int v = x.first, w = x.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    for(int u = 1; u <= n; u++){
        for(auto x : G[u]){
            int v = x.first, w = x.second;
            if(dist[u] + w < dist[v]){
                *ok = false;
            }
        }
    }
    return dist;
}

void Johnson(){
    int q = n + 1;
    vector <pair <ll,ll>> GG[N];
    for(int i = 1; i <= n; i++){
        GG[i] = G[i];
        //cout << "Hello\n";
    }
    for(int v = 1; v <= n; v++){
        GG[q].push_back({v, 0});
    }
    vector <ll> h = BellmanFord(q, &ok);
    if(!ok){
        cout << "Negative Cycle!\n";
        return;
    }
    for(int u = 1; u <= n; u++){
        for(auto x : G[u]){
            int v = x.first, w = x.second;
            weight[u][v] = weight[u][v] + h[u] - h[v];
        }
    }
    vector <ll> pre(N);
    for(ll u = 1; u <= n; u++){
        vector <ll> temp = dijkstra(u, pre);
        for(ll v = 1; v <= n; v++){
            d[u][v] = temp[v];
            ll it = v;

            while(pre[it] != -1){
                cnt[{min(it, pre[it]), max(it, pre[it])}]++;
                it = pre[it];
            }
            // cnt[{min(u, it), max(u, it)}]++;
        }
    }

    /*
    for(int u = 1; u <= n; u++){
        vector <ll> temp = dijkstra(u);
        for(int v = 1; v <= n; v++){
            d[u][v] = temp[v];
        }
    }
    */

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            d[u][v] = d[u][v] + h[v] - h[u];
        }
    }
    //cout << "Done!\n";
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            weight[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        weight[u][v] = w;
    }

    vector <ll> pre(N);
    //vector <ll> dist = BellmanFord(1, &ok);
    //vector <ll> dist = dijkstra(1);
    vector <ll> dist = dijkstra(1, pre);

    for(int i = 1; i <= n; i++){
        cout << "dist[" << i << "] = " << dist[i] << "\n";
    }
    vector <ll> path;
    ll v = n;
    path.push_back(v);
    while(pre[v] != -1){
        path.push_back(pre[v]);
        v = pre[v];
    }
    reverse(path.begin(), path.end());
    for(auto x : path){
        cout << x << " ";
    }
    cout << "\n";

    Johnson();
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            cout << setw(20) << d[u][v] << " ";
        }
        cout << "\n";
    }
    int x, y, z = 0;
    for(auto it : cnt){
        if(it.second > z){
            z = it.second;
            x = it.first.first;
            y = it.first.second;
        }
        cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
    }

    cout << x << " " << y << " " << z << "\n";

    return 0;
}

/*

4 5
1 2 4
1 3 1
2 3 2
2 4 5
3 4 3

*/

