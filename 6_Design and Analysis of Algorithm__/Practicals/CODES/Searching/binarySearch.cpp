#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n, i, k, mid, beg = 0, end;
    clock_t t1, t2;
    float t;

    cout << "\nEnter number of elements you want to enter: ";
    cin >> n;

    int a[n];

    cout << "\nEnter Values:-" << endl;
    for (i = 0; i < n; i++) {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nEnter an element you want to search: ";
    cin >> k;

    t1 = clock();

    end = n - 1;
    mid = (beg + end) / 2;

    if (a[beg] == k) {
        cout << "\nElement Found!!... Location --> " << beg << endl;
    }

    else if (a[end] == k) {
        cout << "\nElement Found!!!... Location --> " << end << endl;
    }

    else {
        while (beg <= end) {
            if (a[mid] == k) {
                cout << "Element Found!!... Location --> " << mid << endl;
                break;
            }
            else if (k < a[mid]) {
                end = mid + 1;
                mid = (beg + end) / 2;
            }
            else if (a[mid] < k) {
                beg = mid - 1;
                mid = (beg + end) / 2;
            }
        }
    }

    if (end <= beg) {
        cout << "Element not found...:(" << endl;
    }

    t2 = clock();
    t = (float)(t2 - t1) / CLOCKS_PER_SEC;

    cout << "Processor time taken in searching position" << t << "seconds";

    return 0;
}
