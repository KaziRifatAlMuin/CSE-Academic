#include<iostream>
#include<fstream>
using namespace std;
class X{
    int cost;
    char name[20];
public:
    void file_write()
    {
        ofstream outf("item.txt");
        cout<<"item name:";
        cin>>name;
        outf<<name<<"\n";
        cout<<"item cost:";
        int cost;
        cin>>cost;
        outf<<cost<<"\n";
        outf.close();
    }
    void file_read(){
        ifstream inf("item.txt");
        inf>>name;
        inf>>cost;
        cout<<"\n";
        cout<<"item:"<<name<<"\n";
        cout<<"expenditure:"<<cost<<"\n";
        inf.close();
    }
};

int main()
{
    X ob1;
    ob1.file_write();
    ob1.file_read();
    return 0;
}
