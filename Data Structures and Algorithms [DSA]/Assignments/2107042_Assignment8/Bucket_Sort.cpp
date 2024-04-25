#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

// Insertion sorting function to sort individual buckets
void insertionSort(vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket sort function
void bucketSort(vector<int>& arr) {
    // Determining the size of the array
    int n = arr.size();

    // Find the minimum and maximum elements in the array
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    // Calculate the range of elements
    int range = maxVal - minVal + 1;

    // Create the number of buckets based on the spread of elements
    int bucketCount = max(1, range / n); // Avoid division by zero and ensure at least one bucket

    // Creating buckets
    vector<vector<int>> b(bucketCount);

    // Putting array elements in different buckets
    for (int i = 0; i < n; i++) {
        // Calculate bucket index using the element's relative position within the range
        int bi = (arr[i] - minVal) * bucketCount / range;
        // Ensure bi is within valid bucket range (0 to bucketCount-1)
        bi = min(bi, bucketCount - 1); // Clamp to last bucket index if needed
        // Adding the current element to the corresponding bucket
        b[bi].push_back(arr[i]);
    }

    // Sorting individual buckets using insertion sort
    for (int i = 0; i < bucketCount; i++) {
        insertionSort(b[i]);
    }

    // Concatenating all buckets into arr[]
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
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

    cout << "Bucket Sort\n";
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
        bucketSort(arr);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // print(arr);
        
        cout << "Time taken for size " << size << ": " << duration.count() << " microseconds" << endl;
    }

    cout << "________________________________________________\n";

    return 0;
}
