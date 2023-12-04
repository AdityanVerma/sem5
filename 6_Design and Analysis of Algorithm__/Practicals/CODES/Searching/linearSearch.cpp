#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n, i, k;
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

    for (i = 0; i < n; i++) {
        if (a[i] == k) {
            cout << "\nElement Found!!... Location --> " << i << endl;
            break;
        }
    }

    if (i == n) {
        cout << "\nElement not found...:(" << endl;
    }

    t2 = clock();
    t = (float)(t2 - t1) / CLOCKS_PER_SEC;

    cout << "Processor time taken in searching is " << t << " seconds" << endl;

    return 0;
}
