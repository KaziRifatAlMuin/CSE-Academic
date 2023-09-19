#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k = 10;
    vector <vector<int>> v;
    int row = 4, col = 5;
    for(int i = 0; i < row; i++){
        vector <int> v1;
        for(int j = 0; j < col; j++){
            v1.push_back(rand()%10);
        }
        v.push_back(v1);
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
