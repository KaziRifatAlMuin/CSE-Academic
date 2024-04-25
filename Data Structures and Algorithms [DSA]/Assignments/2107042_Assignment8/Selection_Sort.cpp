#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // Iterating through the array from 0 to n-1
    for (int i = 0; i < n-1; ++i) {
        // Assuming the current element as the minimum
        int min_idx = i;
        // Finding the index of the minimum element in the unsorted part of the array
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swapping the current element with the minimum element found
        swap(arr[i], arr[min_idx]);
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

    cout << "Selection Sort\n";
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
        selectionSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
