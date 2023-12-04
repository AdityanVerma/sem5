#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const int prime = 101;  // Prime number for hashing

void rabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    const int d = 256;  // Number of characters in the input alphabet

    int h = 1;
    for (int i = 0; i < m - 1; ++i)
        h = (h * d) % prime;

    int patternHash = 0;
    int textHash = 0;

    // Calculate the initial hash values
    for (int i = 0; i < m; ++i) {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << "\n";
        }

        if (i < n - m) {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }
}

int main() {
    clock_t t1,t2;
    float t;
    t1=clock();
    string text = "ABABCABABABCABABC";
    string pattern = "ABABC";
    cout<<"String text "<<text<<"\n";
    cout<<"String pattern "<<pattern<<"\n";
    cout<<"Rabin-Karp Algorithm:-\n";
    rabinKarp(text, pattern);
    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;

    cout << "\nProcessing Time is " << t << " seconds.\n\n";
    return 0;
}
