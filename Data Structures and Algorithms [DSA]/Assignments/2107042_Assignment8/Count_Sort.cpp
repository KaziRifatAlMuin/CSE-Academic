#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

void countSort(vector<int>& arr) {
    // Finding the maximum element in the array.
    int max_element_val = *max_element(arr.begin(), arr.end());
    // Creating a count array to store the occurrence count of each element.
    vector<int> count(max_element_val + 1, 0);
    // Creating an output array to store the sorted elements.
    vector<int> output(arr.size());

    // Counting the occurrences of each element in the input array.
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
    }

    // Modifying the count array to store the cumulative count of elements.
    for (int i = 1; i <= max_element_val; ++i) {
        count[i] += count[i - 1];
    }

    // Building the output array by placing elements in correct positions based on the count array.
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copying the sorted elements from the output array back to the original array.
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
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

    cout << "Count Sort\n";
    cout << "________________________________________________\n";

    for (int size : inputSizes) {

        // Generatng Random Array
        vector<int> arr(size);
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> dist(1, size * 100);
        for (int& num : arr) {
            num = dist(rng);
        }

        // Performing Sorting and Measure Time
        auto start = high_resolution_clock::now();
        countSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
