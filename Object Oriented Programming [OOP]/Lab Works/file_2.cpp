#include<iostream>
#include<fstream>
using namespace std;
class X{
    public:
    void file_write()
    {
        ofstream fout;
        fout.open("country.txt");
        fout<<"USA\t";
        fout<<"UK";
        fout.close();
        fout.open("capital.txt");
        fout<<"Washington\t";
        fout<<"London\n";
        fout.close();
    }
    void file_read(){
        char line[50];
        ifstream fin;
        fin.open("country.txt");
        cout<<"The contents of the country file:\n";
        while(fin)
        {
            fin.getline(line,50);
            cout<<line;
        }
        fin.close();
        fin.open("capital.txt");
        cout<<"\nThe contents of the capital file:\n";
        while(fin)
        {
            fin.getline(line,50);
            cout<<line;
        }
        fin.close();
    }
};
int main()
{
    X ob1;
    ob1.file_write();
    ob1.file_read();
    return 0;
}
