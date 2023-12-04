#include <iostream>
#include <ctime>

using namespace std;

// Heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() 
{
    int n, i;
    
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    
    int a[n];
    clock_t t1, t2;
    double t;
    
    
    cout << "Enter the elements:-" << endl;
    for(i=0; i<n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    
    cout << "\nArray before sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }

    t1 = clock();
    
    heapSort(a, n); // Pass Array in Sorting Function
    
    cout << "\nArray after sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    t2 = clock();
    t = (double) (t2 - t1)/CLOCKS_PER_SEC;
    cout << "\nTotal time taken by code: " << t << " seconds.";
    
    return 0;
}
