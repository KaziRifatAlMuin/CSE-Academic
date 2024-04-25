#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    // Selecting the last element as the pivot
    int pivot = arr[high];
    // Initializing the index of the smaller element
    int i = low - 1;
    // Iterating through the array from low to high-1
    for (int j = low; j <= high - 1; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] < pivot) {
            // Incrementing the index of the smaller element
            i++;
            // Swapping arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
    }
    // Swapping arr[i+1] and arr[high] (pivot)
    swap(arr[i+1], arr[high]);
    // Returning the pivot index
    return i + 1;
}

// Function to recursively sort the array using Quick Sort algorithm
void quickSortHelper(vector<int>& arr, int low, int high) {
    // Base case: if low is less than high
    if (low < high) {
        // Partitioning the array and getting the pivot index
        int pi = partition(arr, low, high);
        // Recursively sorting the sub-arrays before and after the pivot
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

// Wrapper function to call the Quick Sort algorithm
void quickSort(vector<int>& arr) {
    int n = arr.size();
    // Calling the helper function with the initial indices
    quickSortHelper(arr, 0, n - 1);
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

    cout << "Quick Sort\n";
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
        quickSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
