#include <iostream>
using namespace std;

class over{
    int num;
public:
    over(){}
    over(int n){num = n;}
    void friend operator- (over &A)
    {
        A.num = -A.num;
    }
    void output(){
        cout << num << "\n";
    }
};

int main()
{
    over A(5), B(10);
    -A;
    -B;
    A.output();
    B.output();
    return 0;
}
