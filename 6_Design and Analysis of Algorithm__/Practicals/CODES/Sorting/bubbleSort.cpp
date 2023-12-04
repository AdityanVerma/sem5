#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    
    bubbleSort(a, n); // Pass Array in Sorting Function
    
    cout << "\nArray after sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    t2 = clock();
    t = (double) (t2 - t1)/CLOCKS_PER_SEC;
    cout << "\nTotal time taken by code: " << t << " seconds.";
    
    return 0;
}
