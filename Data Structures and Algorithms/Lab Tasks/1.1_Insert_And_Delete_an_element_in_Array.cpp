#include <iostream>
using namespace std;

void PrintArray(int ara[], int n)
{
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }
    cout << "\n";
}

void Insertion(int ara[], int n, int pos, int value, int * ArraySize)
{
    for(int i = n - 1; i >= pos; i--){
        ara[i+1] = ara[i];
    }
    ara[pos] = value;
    *ArraySize = n + 1;
}

void Deletetion(int ara[], int n, int pos, int * ArraySize)
{
    for(int i = pos; i < n - 1; i++){
        ara[i] = ara[i+1];
    }
    *ArraySize = n - 1;
}

int main()
{
    int ara[10000];
    cout << "Enter Array Size : ";
    int n;
    cin >> n;
    cout << "Enter The Array Elements :\n";
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    int opt = 1;
    while(opt){
        cout << "Choose an Operation : \n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "0. Exit\n";
        cin >> opt;
        if(opt == 1){
            cout << "Enter The Position and Value : ";
            int x, a;
            cin >> x >> a;
            Insertion(ara, n, x, a, &n);
            PrintArray(ara, n);
        }
        else if(opt == 2){
            cout << "Enter The Position : ";
            int x;
            cin >> x ;
            Deletetion(ara, n, x, &n);
            PrintArray(ara, n);
        }
    }
}