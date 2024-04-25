#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Merge function to merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int l, int m, int r) {
    // Determining the sizes of the two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Creating temporary arrays to hold the left and right subarrays
    vector<int> L(n1), R(n2);

    // Copying data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    // Merging the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copying the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on the array
void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Calculating the middle index
        int m = l + (r - l) / 2;

        // Recursively sorting the two halves
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);

        // Merging the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to call the merge sort algorithm on the entire array
void mergeSort(vector<int>& arr) {
    int n = arr.size();
    // Calling the helper function with the initial indices
    mergeSortHelper(arr, 0, n - 1);
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

    cout << "Merge Sort\n";
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
        mergeSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
