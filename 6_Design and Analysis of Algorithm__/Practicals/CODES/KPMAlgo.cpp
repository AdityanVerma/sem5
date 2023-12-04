#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << "\n";
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    clock_t t1,t2;
    float t;
    t1=clock();
    string text = "ABABCABABABCABABC";
    string pattern = "ABABC";
    cout<<"string text "<<text<<"\n";
    cout<<"string pattern "<<pattern<<"\n";
    cout << "Knuth-Morris-Pratt (KMP) Algorithm:\n";
    kmp(text, pattern);
    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";
    return 0;
}
