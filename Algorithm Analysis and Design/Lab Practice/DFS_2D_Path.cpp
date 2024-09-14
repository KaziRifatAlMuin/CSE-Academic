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
string path;
pair <int, int> last;

void DFS(pair <int, int> prev, pair <int, int> node){
    int x1 = prev.first, y1 = prev.second, x2 = node.first, y2 = node.second;
    // cout << "[" << node.first << "," << node.second << "]" << " ";
    visited[x2][y2] = true;
    if(x1 != -1){
        if(x1 - x2 == 1) path += 'U';
        else if(x1 - x2 == -1) path += 'D';
        else if(y1 - y2 == 1) path += 'L';
        else path += 'R'; 
        last = {x2, y2};
    }
    for(int i = 0; i < 4; i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        if(!visited[x][y] && x > 0 && x <= n && y > 0 && y <= m && s[x][y] == '*'){
            DFS({x2,y2}, {x,y});
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
    int ans = 0, flag = 1;
    for(int i = 1; i <= n && flag; i++){
        for(int j = 1; j <= m && flag; j++){
            if(s[i][j] == 'S'){
                DFS({-1,-1}, {i,j});
                pair <int, int> node = {i,j};
                int x1 = last.first, y1 = last.second, x2 = node.first, y2 = node.second;
                if(x1 - x2 == 1) path += 'U';
                else if(x1 - x2 == -1) path += 'D';
                else if(y1 - y2 == 1) path += 'L';
                else path += 'R'; 
                flag = 0;
            }
        }
    }
    cout << path << "\n";
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
// https://codeforces.com/problemset/problem/648/C