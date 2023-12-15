#include <iostream>
using namespace std;

class Array{
	int size;
	int *arr;
public:
	Array()
	{
		size = 0;
		arr = new int;
	}
	void createArray(int n)
	{
		size = n;
		for(int i = 0; i < n; i++){
			arr[i] = 0;
		}
	}
};

int main()
{
	cout << "OK!\n";
	return 0;
}