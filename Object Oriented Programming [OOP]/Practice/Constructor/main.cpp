#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int x = 0, int y = 0) : val1(x), val2(y) {}
    void display() {
        cout << "val1: " << val1 << endl;
        cout << "val2: " << val2 << endl;
    }
private:
    int val1;
    int val2;
};

int main() {
    MyClass obj;
    obj.display();
    MyClass obj2(4, 5);
    obj2.display();
    MyClass obj3(5);
    obj3.display();

    return 0;
}
