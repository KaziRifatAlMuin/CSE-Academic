#include <iostream>
#include <fstream>
using namespace std;

class X{
    string name;
    int age;
public:
    void file_write()
    {
        ofstream outf;
        outf.open("student.details2.txt");
        for(int i = 0; i < 3; i++){
            cout << "Enter Your Name : " << endl;
            getline(cin, name);
            cout << "Enter your age : " << endl;
            cin >> age;
            outf << name << "\t" << age << endl;
            cin.ignore();
        }
        outf.close();
    }
};

int main()
{
    X ob1;
    ob1.file_write();
    //cout << "Hello world!" << endl;
    return 0;
}
