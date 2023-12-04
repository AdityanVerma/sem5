#include <iostream>
#include <ctime>

using namespace std;

// Function to partition the array into two halves
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform quicksort on the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    quickSort(a, 0, n-1); // Pass Array in Sorting Function
    
    cout << "\nArray after sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    t2 = clock();
    t = (double) (t2 - t1)/CLOCKS_PER_SEC;
    cout << "\nTotal time taken by code: " << t << " seconds.";
    
    return 0;
}
