#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1005;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char s[N][N];
bool visited[N][N] = {false};
vector <pair<int,int>> graph[N];

void DFS(pair <int, int> node){
    visited[node.first][node.second] = true;
    // cout << "[" << node.first << "," << node.second << "]" << " ";
    for(int i = 0; i < 4; i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        if(!visited[x][y] && x > 0 && x <= n && y > 0 && y <= m && s[x][y] == '.'){
            DFS({x,y});
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && s[i][j] == '.'){
                DFS({i,j});
                // cout << "\n";
                ans++;
            }
        }
    }
    cout << ans << "\n";
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