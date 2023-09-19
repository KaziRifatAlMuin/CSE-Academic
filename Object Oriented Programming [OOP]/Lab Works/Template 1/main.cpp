// function template
#include <iostream>
using namespace std;
template <typename T>
T GetMin (T a, T b)
{
    T result;
    result = (a<b)? a : b;
    return (result);
}

int main ()
{
    int i = 4, j = 6, k;
    long long l = 10, m = 5, n;
    k = GetMin(i,j);
    n = GetMin<long long>(l,m);
    cout << k << endl;
    cout << n << endl;
    cout << GetMin(7.9, 7.1) << endl;

    return 0;
}
