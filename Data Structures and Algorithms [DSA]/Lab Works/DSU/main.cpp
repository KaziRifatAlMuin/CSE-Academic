#include <iostream>
using namespace std;
int const N = 10000;

class DSU{
    int parent[N];
public:
    DSU(){}
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
    }

    bool is_Same_set(int a, int b){
        return find_set(a) == find_set(b);
    }
};

int main()
{
    DSU dsu;
    dsu.make_set(1);
    dsu.make_set(2);
    dsu.make_set(3);
    dsu.make_set(4);
    dsu.make_set(5);
    dsu.make_set(6);

    dsu.union_set(1,2);
    dsu.union_set(1,3);
    dsu.union_set(4,5);

    cout << dsu.is_Same_set(2,3) << "\n";
    cout << dsu.is_Same_set(1,4) << "\n";
    cout << dsu.is_Same_set(3,4) << "\n";
    cout << dsu.is_Same_set(4,5) << "\n";

    dsu.union_set(3,6);
    dsu.union_set(1,5);

    cout << dsu.is_Same_set(3,4) << "\n";
    cout << dsu.is_Same_set(2,6) << "\n";
}
