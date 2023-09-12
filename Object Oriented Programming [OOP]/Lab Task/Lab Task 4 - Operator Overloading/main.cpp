#include <iostream>
using namespace std;

class Money{
    int Dollars;
    int Cents;
public:
    Money()
    {
        Dollars = 0;
        Cents = 0;
    }
    Money(int Dollars, int Cents)
    {
        this->Dollars = Dollars;
        this->Cents = Cents;
    }

    Money operator+(Money M)
    {
        Money Add;
        Add.Dollars = Dollars + M.Dollars;
        if(Cents + M.Cents >= 100){
            Add.Cents = Cents + M.Cents - 100;
            ++Add.Dollars;
        }
        else{
            Add.Cents = Cents + M.Cents;
        }
        return Add;
    }

    Money operator-(Money M)
    {
        Money Sub;
        Sub.Dollars = Dollars - M.Dollars;
        if(Cents < M.Cents){
            Sub.Cents = Cents + 100 - M.Cents;
            --Sub.Dollars;
        }
        else{
            Sub.Cents = Cents - M.Cents;
        }
        return Sub;
    }

    void display()
    {
        cout << "Dollars : " << Dollars << "\n";
        cout << "Cents   : " << Cents << "\n";
    }
};

int main()
{
    Money m1(13, 60), m2(10, 70);
    Money m3 = m1 + m2;
    Money m4 = m1 - m2;

    m1.display();
    m2.display();

    cout << "\nAddition Result : \n";
    m3.display();
    cout << "\nSubtraction Result : \n";
    m4.display();

    return 0;
}
