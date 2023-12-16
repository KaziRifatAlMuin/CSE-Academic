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
	void insertElement(int index, int value)
	{
		if(index < 0 || index > size){
			cout << "Invalid Index!\n";
			return;
		}
		for(int i = size - 1; i >= index; i--){
	        arr[i+1] = arr[i];
	    }
	    arr[index] = value;
	    ++size;

	}
	void deleteElement(int index)
	{
		if(index < 0 || index >= size){
			cout << "Invalid Index!\n";
			return;
		}
		for(int i = index; i < size - 1; i++){
	        arr[i] = arr[i+1];
	    }
	    --size;
	}
	int searchElement(int value)
	{
		for(int i = 0; i < size; i++){
			if(arr[i] == value){
				return i;
			}
		}
		return -1;
	}
	void traverseArray()
	{
		for(int i = 0; i < size; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	int& operator[](int index) {
        if (index < size && index >= 0) {
            return arr[index];
        } 
        else {
            std::cerr << "Index out of Bounds!" << std::endl;
            exit(1);
        }
    }
};

int main()
{
	cout << "OK!\n";
	Array ara;

	int opt = 1;
	while(opt){
		cout << "Choose an option : \n";
		cout << "------------------------------\n";
		cout << "1. Create an Array \n";
		cout << "2. Insert an Element \n";
		cout << "3. Delete an Element \n";
		cout << "4. Search an Element \n";
		cout << "5. Traverse Array \n";
		cout << "0. Exit \n";
		cin >> opt;
		if(opt == 1){
			cout << "Enter the array size : ";
			int n;
			cin >> n;
			ara.createArray(n);
			cout << "Enter the Elements : \n";
			for(int i = 0; i < n; i++){
				cin >> ara[i];
			}
		}
		else if(opt == 2){
			int v, ix;
			cout << "Enter the Index : ";
			cin >> ix;
			cout << "Enter the Value : ";
			cin >> v;
			ara.insertElement(ix, v);
			cout << "------------------------------\n";
			ara.traverseArray();
		}
		else if(opt == 3){
			int ix;
			cout << "Enter the Index : ";
			cin >> ix;
		
			ara.deleteElement(ix);
			cout << "------------------------------\n";
			ara.traverseArray();
		}
		else if(opt == 4){
			int v;
			cout << "Enter the Value : ";
			cin >> v;
			int ix = ara.searchElement(v);
			cout << "------------------------------\n";
			if(ix == -1){
				cout << "The element not Found!\n";
			}
			else{
				cout << "The element is in the index " << ix << "\n";
			}
		}
		else if(opt == 5){
			cout << "------------------------------\n";
			ara.traverseArray();
		}
		else{
			cout << "Wrong Key!\n";
		}
		cout << "------------------------------\n";
	}

	return 0;
}