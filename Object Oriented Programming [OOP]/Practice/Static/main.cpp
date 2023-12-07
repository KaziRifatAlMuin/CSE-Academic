#include <iostream>
using namespace std;

class MyClass {
    int a;
public:
    static int staticVariable;
    static void staticFunction()
    {
        //cout << a << "\n";
        cout << "Static function called. The static variable value is: " << staticVariable << endl;
    }
};

int MyClass::staticVariable = 0;

int main() {
    MyClass obj1;
    MyClass obj2;

    //cout << "Static variable value after creating two objects: " << MyClass::staticVariable << endl;

    MyClass::staticFunction();
    obj1.staticFunction();

    return 0;
}
