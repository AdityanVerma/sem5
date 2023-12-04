#include <iostream>
#include <vector>

using namespace std;

// Function to perform a comparison and swap if necessary
void compareAndSwap(int& a, int& b) {
    if (a > b) {
        swap(a, b);
    }
}

// Function to perform a batcher's merge operation
void batchersMerge(vector<int>& arr, int l, int r, int d) {
    if (d > 0) {
        int k = 1 << (d - 1);
        for (int i = l; i + k <= r; ++i) {
            compareAndSwap(arr[i], arr[i + k]);
        }
        batchersMerge(arr, l, r, d - 1);  // Recursively merge smaller subproblems
        batchersMerge(arr, l + k, r + k, d - 1);
    }
}

// Function to perform Batcher's odd-even mergesort
void batchersOddEvenMergesort(vector<int>& arr, int l, int r, int d) {
    if (d == 0) {
        compareAndSwap(arr[l], arr[r]);
    } else {
        int m = (l + r) / 2;
        batchersOddEvenMergesort(arr, l, m, d - 1);   // Odd phase
        batchersOddEvenMergesort(arr, m + 1, r, d - 1); // Even phase
        batchersMerge(arr, l, r, d - 1);
    }
}

// Function to perform sorting network
void sortingNetwork(vector<int>& arr, int n) {
    int d = 1;  // Number of bits in the binary representation of the array size

    while ((1 << d) < n) {
        batchersOddEvenMergesort(arr, 0, n - 1, d);
        d++;
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    cout << "Original Array: ";
    printArray(arr);

    sortingNetwork(arr, arr.size());

    cout << "Sorted Array: ";
    printArray(arr);
    return 0;
}
