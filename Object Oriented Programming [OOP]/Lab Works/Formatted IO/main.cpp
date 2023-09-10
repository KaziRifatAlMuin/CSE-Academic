#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << 45678 << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(8);
    cout.fill('*');
    cout << 45678 << endl;
    //cout.fixed(2)
    cout.precision(10);
    cout << sqrt(2) << endl;

    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::showbase);

    cout << 94 << endl;
    cout << 95 << endl;
    cout << 96 << endl;

    cout.unsetf(ios::hex);

    cout << 97 << endl;


    return 0;
}
