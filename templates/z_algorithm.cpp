// Z-Algorithm Template
// z[i] = length of longest substring starting from s[i] that is also a prefix of s

#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n; // The entire string matches itself
    
    int l = 0, r = 0; // [l, r] is the rightmost segment that matches a prefix
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            // We're inside a Z-box, use previously computed values
            z[i] = min(r - i + 1, z[i - l]);
        }
        
        // Try to extend the match
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        // Update the Z-box if we found a longer match
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

// Comparison with KMP next array
vector<int> kmp_next(string s) {
    int n = s.size();
    vector<int> next(n);
    next[0] = -1;
    
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }
    
    return next;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    vector<int> z = z_function(s);
    vector<int> next = kmp_next(s);
    
    cout << "String: " << s << endl;
    cout << "Z-array: ";
    for (int x : z) cout << x << " ";
    cout << endl;
    
    cout << "Next array: ";
    for (int x : next) cout << x << " ";
    cout << endl;
    
    return 0;
}
