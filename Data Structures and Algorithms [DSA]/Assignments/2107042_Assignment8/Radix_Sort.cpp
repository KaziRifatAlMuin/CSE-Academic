#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to perform counting sort based on digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    // Output array to store the sorted elements
    vector<int> output(arr.size());
    // Count array to store the count of occurrences of each digit
    vector<int> count(10, 0);

    // Counting the occurrences of each digit at the given exponent position
    for (int i = 0; i < arr.size(); ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Updating count array to store the actual position of each digit in output array
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Building the output array by placing elements in sorted order based on the digit at exp position
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copying the sorted elements from output array to original array
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    // Finding the maximum element in the array
    int max_element_val = *max_element(arr.begin(), arr.end());

    // Performing counting sort for each digit, starting from least significant digit to most significant digit
    for (int exp = 1; max_element_val / exp > 0; exp *= 10) {
        countingSort(arr, exp);
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

    cout << "Radix Sort\n";
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
        radixSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
