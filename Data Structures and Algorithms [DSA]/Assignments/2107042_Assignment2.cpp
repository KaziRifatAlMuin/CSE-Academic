/*
	Name : Kazi Rifat Al Muin
	Roll : 2107042
	Assignment No : 02
	Topic : Implementing Binary Search Algorithms and more functionalities
*/

#include <iostream>
#include <algorithm>
#include <math.h>
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
    void SortArray()
    {
    	sort(arr, arr + size);
    }
    int binary_search(int value)
    {
    	try{
    		for(int i = 1; i < size; i++){
    			if(arr[i] < arr[i-1]){
    				throw -2;
    			}
    		}
    		int low = 0, high = size - 1;
    		while(low <= high){
    			int mid = (low + high) / 2;
    			if(arr[mid] == value){
    				return mid;
    			}
    			else if(arr[mid] < value){
    				low = mid + 1;
    			}
    			else{
    				high = mid - 1;
    			}
    		}
    		return -1;
    	}
    	catch(int x){
    		cout << "Error! Array is not sorted!\n";
    		return -2;
    	}
    }
    int lower_bound(int value)
    {
    	try{
    		for(int i = 1; i < size; i++){
    			if(arr[i] < arr[i-1]){
    				throw -2;
    			}
    		}
    		if(value < arr[0] || value > arr[size - 1]){
    			return -1;
    		}
    		int low = 0, high = size - 1, ans = -1;
    		while(low <= high){
    			int mid = (low + high) / 2;
    			if(arr[mid] >= value){
    				ans = mid;
    				high = mid - 1;
    			}
    			else{
    				low = mid + 1;
    			}
    		}
    		return ans;
    	}
    	catch(int x){
    		cout << "Error! Array is not sorted!\n";
    		return -2;
    	}
    }
    int upper_bound(int value)
    {
    	try{
    		for(int i = 1; i < size; i++){
    			if(arr[i] < arr[i-1]){
    				throw -2;
    			}
    		}
    		if(value >= arr[size - 1]){
    			return -1;
    		}
    		int low = 0, high = size - 1, ans = -1;
    		while(low <= high){
    			int mid = (low + high) / 2;
    			if(arr[mid] > value){
    				ans = mid;
    				high = mid - 1;
    			}
    			else{
    				low = mid + 1;
    			}
    		}
    		return ans;
    	}
    	catch(int x){
    		cout << "Error! Array is not sorted!\n";
    		return -2;
    	}
    }
    int One_Sided_binary_search(int value)
    {
    	try{
    		for(int i = 1; i < size; i++){
    			if(arr[i] < arr[i-1]){
    				throw -2;
    			}
    		}
		    int bits = log2(size-1) + 1, pos = 0;
	        for(int i = bits; i >= 0; i--) {
	            if(arr[pos] == value) {
	                return pos;
	            }
	            int npos = pos | (1 << i);
	    		if((npos < size) && (arr[npos] <= value)) {
	                pos = npos;
	            }
	        }
	        return ((arr[pos] == value) ? pos : -1);
	    }
    	catch(int x){
    		cout << "Error! Array is not sorted!\n";
    		return -2;
    	}
    }
};

int main()
{
	Array ara;
	int opt = 1;
	while(opt){
		cout << "1. Create an Array \n";
		cout << "2. Insert an Element \n";
		cout << "3. Delete an Element \n";
		cout << "4. Search an Element \n";
		cout << "5. Traverse Array \n";
		cout << "6. Binary Search an Element \n";
		cout << "7. Sort The Array \n";
		cout << "8. Lower Bound \n";
		cout << "9. Upper Bound \n";
		cout << "10. One-Sided Binary Search\n";
		cout << "0. Exit \n";
		cout << "------------------------------\n";
		cout << "Choose an option : ";
		cin >> opt;
		if(opt == 1){
			cout << "Enter the array size : ";
			int n;
			cin >> n;
			ara.createArray(n);
			cout << "Enter the Elements : ";
			for(int i = 0; i < n; i++){
				cin >> ara[i];
			}
			cout << "------------------------------\n";
			cout << "The array is created! \n";
		}
		else if(opt == 2){
			int v, ix;
			cout << "Enter the Index : ";
			cin >> ix;
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			ara.insertElement(ix, v);
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
			cout << "------------------------------\n";
			ara.traverseArray();
			cout << "------------------------------\n";
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			int ix = ara.searchElement(v);
			if(ix == -1){
				cout << "The element not Found!\n";
			}
			else if(ix == -2){
				cout << "\n";
			}
			else{
				cout << "The element is in the index " << ix << "\n";
			}
		}
		else if(opt == 5){
			cout << "------------------------------\n";
			ara.traverseArray();
		}
		else if(opt == 6){
			cout << "------------------------------\n";
			ara.traverseArray();
			cout << "------------------------------\n";
			int v;
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			int ix = ara.binary_search(v);
			if(ix == -1){
				cout << "The element not Found!\n";
			}
			else if(ix == -2){}
			else{
				cout << "The element is in the index " << ix << "\n";
			}
		}
		else if(opt == 7){
			cout << "------------------------------\n";
			ara.SortArray();
			ara.traverseArray();
		}
		else if(opt == 8){
			cout << "------------------------------\n";
			ara.traverseArray();
			cout << "------------------------------\n";
			int v;
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			int ix = ara.lower_bound(v);
			if(ix == -1){
				cout << "Not Found!\n";
			}
			else if(ix == -2){}
			else{
				cout << "Lower Bound is " << ix << "\n";
			}
		}
		else if(opt == 9){
			cout << "------------------------------\n";
			ara.traverseArray();
			cout << "------------------------------\n";
			int v;
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			int ix = ara.upper_bound(v);
			if(ix == -1){
				cout << "Not Found!\n";
			}
			else if(ix == -2){}
			else{
				cout << "Upper Bound is " << ix << "\n";
			}
		}
		else if(opt == 10){
			cout << "------------------------------\n";
			ara.traverseArray();
			cout << "------------------------------\n";
			int v;
			cout << "Enter the Value : ";
			cin >> v;
			cout << "------------------------------\n";
			int ix = ara.One_Sided_binary_search(v);
			if(ix == -1){
				cout << "The element not Found!\n";
			}
			else if(ix == -2){}
			else{
				cout << "The element is in the index " << ix << "\n";
			}
		}
		else if(opt == 0){
            break;
		}
		else{
            cout << "Wrong Key!\n";
		}
		cout << "------------------------------\n";
	}
	return 0;
}
