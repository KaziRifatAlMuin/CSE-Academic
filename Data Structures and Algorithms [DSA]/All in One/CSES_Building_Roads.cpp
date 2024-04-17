#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;

vector <int> graph[N];
bool visited[N];

void DFS(int node){
    visited[node] = true;
    for(auto child : graph[node]){
        if(!visited[child]){
            DFS(child);
        }
    }
}

void solve()
{
    int n, m, prev;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = false;
    vector <pair <int, int>> roads;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(flag) roads.push_back({prev, i});
            else flag = true;
            prev = i;
            DFS(i);
        }
    }
    cout << roads.size() << "\n";
    for(auto x : roads){
        cout << x.first << " " << x.second << "\n";
    }
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