#include <iostream>
using namespace std;
int const N = 10000;

int parent[N];
int money[N];
int cnt[N];
int total[N];

void make_set(int v){
    parent[v] = v;
}

int find_set(int v){
    if(parent[v] == v) return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_set(int a, int b){
    int root_a = find_set(a);
    int root_b = find_set(b);
    parent[root_b] = root_a;
    cnt[root_a] = cnt[root_a] + cnt[root_b];
    total[root_a] = total[root_a]+total[root_b];
}

bool is_Same_set(int a, int b){
    return find_set(a) == find_set(b);
}

double Query(int u){
    int root_u = find_set(u);
    double ans = (double) total[root_u] / (cnt[root_u]);
    return ans;
}

int main()
{
    int n;
    //cout << "Enter number of user : ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        make_set(i);
    }
    //cout << "Enter amount of money : ";
    for(int i = 1; i <= n; i++){
        cin >> money[i];
        total[i] = money[i];
        cnt[i] = 1;
    }
    //cout << "Enter Number of Query : ";
    int q;
    cin >> q;
    while(q--){
        char c;
        int u, v;
        cin >> c;
        if(c == 'F'){
            cin >> u >> v;
            union_set(u, v);
        }
        else{
            cin >> u;
            cout << Query(u) << "\n";
        }
    }
}

/*
input :

5
10 20 30 40 50
5
F 1 2
F 3 4
Q 3
F 1 3
Q 2

*/
