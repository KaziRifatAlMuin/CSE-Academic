// function template
#include <iostream>
using namespace std;
template <class T>
T GetMax (T a, T b)
{
    T result;
    result = (a>b)? a : b;
    return (result);
}

template <class A, class B>
B GetMin(A a, B b)
{
    B result;
    result = a < b ? a : b;
    return result;
}

int main ()
{
    int i = 5, j = 6, k;
    long long l = 10, m = 5, n;
    k = GetMax<int>(i,j);
    n = GetMax<long long>(l,m);
    cout << k << endl;
    cout << n << endl;

    int a = 42;
    double b = 3.1416;
    cout << GetMin(a,b) << endl;

    return 0;
}
