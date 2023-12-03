#include <iostream>
#include <ctime>

using namespace std;

void selection(int array[], int n);

int main() 
{
    int n, i;
    
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    
    int a[n];
    clock_t t1, t2;
    double t;
    
    t1 = clock();
    
    cout << "Enter the elements:-" << endl;
    for(i=0; i<n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    
    cout << "\nArray before sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    selection(a, n); // Pass Array in Sorting Function
    
    cout << "\nArray after sort: ";
    for(i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    t2 = clock();
    
    t = (double) (t2 - t1)/CLOCKS_PER_SEC;
    
    cout << "\nTotal time taken by code: " << t;
    
    return 0;
}

void selection(int array[], int n) 
{
    int i, j, pos;
    for(i=0; i<n-1; i++) {
        pos = i;
        for(j=i+1; j<n; j++) {
            if(array[pos] > array[j]) {
                pos = j;
            }
        }
        if(pos!=i) {
            int c = array[i];
            array[i] = array[pos];
            array[pos] = c;
        }
    }
}
