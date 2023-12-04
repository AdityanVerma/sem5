#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void naiveStringMatching(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
            cout << "Pattern found at index " << i << "\n";
    }
}

int main() {
    clock_t t1,t2;
    float t;
    t1=clock();
    string text = "ABABCABABABCABABC";
    string pattern = "ABABC";
    
    cout<<"String text: "<<text<<"\n";
    cout<<"String pattern: "<<pattern<<"\n";
    cout << "Naïve String Matching Algorithm: \n";
    naiveStringMatching(text, pattern);
    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";
    return 0;
}
