#include <iostream>

using namespace std;

template <class T>
class mypair{
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }
    T getmax();
    T getmin()
    {
        return a < b ? a : b;
    }
};

template <class T>
T mypair<T> :: getmax()
{
    return a > b ? a : b;
}


int main()
{
    mypair<int> ob(12,18);
    cout << ob.getmax() << endl;
    cout << ob.getmin() << endl;
}
