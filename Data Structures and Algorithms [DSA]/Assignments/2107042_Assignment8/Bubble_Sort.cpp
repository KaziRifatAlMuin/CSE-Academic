#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Outer loop runs n-1 times
    for (int i = 0; i < n-1; ++i) {
        // Inner loop runs from 0 to n-i-1
        for (int j = 0; j < n-i-1; ++j) {
            // Compares adjacent elements
            if (arr[j] > arr[j+1]) {
                // Swaps if the current element is greater than the next one
                swap(arr[j], arr[j+1]);
            }
        }
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

    cout << "Bubble Sort\n";
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
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
