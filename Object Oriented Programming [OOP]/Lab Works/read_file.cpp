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
        outf.open("Student.txt");
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
    void file_read()
    {
        ifstream inf;
        inf.open("Student.txt");
        char line[50];
        while(inf)
        {
            inf.getline(line, 50);
            cout << line;
        }

        inf.close();
    }
};

int main()
{
    X ob1;
    ob1.file_write();
    ob1.file_read();
    //cout << "Hello world!" << endl;
    return 0;
}

