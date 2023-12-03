#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int a[50], n, i, k;
    clock_t t1, t2;
    float t;

    t1 = clock();

    cout << "Enter size of array" << endl;
    cin >> n;

    cout << "Enter the values" << endl;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the element to be searched" << endl;
    cin >> k;
    for (i = 0; i < n; i++) {
        if (a[i] == k)
        {
            cout << "Element found" << endl;
            break;
        }
    }
    if (i == (n - 1)) {
        cout << "Element not found" << endl;
    }

    t2 = clock();
    t = (float)(t2 - t1) / CLOCKS_PER_SEC;

    cout << "Processor time taken in searching position" << t << "seconds";

    return 0;
}
