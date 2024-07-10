#include <iostream>
using namespace std;
int const N = 10000;



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
