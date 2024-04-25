#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    // Iterating through the array starting from the second element
    for (int i = 1; i < n; ++i) {
        // Storing the current element in a variable key
        int key = arr[i];
        // Moving elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; // Shifting element to the right
            j--;
        }
        arr[j+1] = key; // Placing key at its correct position in the sorted subarray
    }
}

void print(vector <int> v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    // Testing different input sizes
    vector<int> inputSizes = {1000, 5000, 10000};

    cout << "Insertion Sort\n";
    cout << "________________________________________________\n";

    for (int size : inputSizes) {
        // Generating Random Array
        vector<int> arr(size);
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> dist(1, size * 100);
        for (int& num : arr) {
            num = dist(rng);
        }

        // Performing Sorting and Measure Time
        auto start = high_resolution_clock::now();
        insertionSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
