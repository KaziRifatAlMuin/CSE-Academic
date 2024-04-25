#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    // Initializing the largest as root
    int largest = i;
    // Calculating the index of the left child
    int l = 2 * i + 1;
    // Calculating the index of the right child
    int r = 2 * i + 2;

    // If the left child exists and is larger than the current largest element
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // If the right child exists and is larger than the current largest element
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // If the largest element is not the root itself
    if (largest != i) {
        // Swapping the largest child with the root
        swap(arr[i], arr[largest]);
        // Recursively heapifying the affected subtree
        heapify(arr, n, largest);
    }
}

void print(vector <int> v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}

// Function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Building heap (rearranging array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // One by one extracting an element from heap
    for (int i = n - 1; i > 0; --i) {
        // Moving current root to end
        swap(arr[0], arr[i]);
        // Calling max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    // Testing different input sizes
    vector<int> inputSizes = {1000, 5000, 10000};

    cout << "Heap Sort\n";
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
        heapSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);

        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
