#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int i, k, n, mid, beg = 0, end;
    clock_t t1, t2;
    float t;

    t1 = clock();

    cout << "Enter number of elements you want to enter: ";
    cin >> n;

    int a[n];

    cout << "Enter Values:-" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter an element you want to search: ";
    cin >> k;

    end = n - 1;
    mid = (beg + end) / 2;

    if (a[beg] == k) {
        cout << "Found it!! Hooray!!... Location --> " << beg << endl;
    }

    else if (a[end] == k) {
        cout << "Found it!! Hooray!!... Location --> " << end << endl;
    }

    else {
        while (beg <= end) {
            if (a[mid] == k) {
                cout << "Found it!! Hooray!!... Location --> " << mid << endl;
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
    cout << "Time taken by code is: " << t;

    return 0;
}
