// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;

// sweep the string
int main() {
    string s;
    cin >> s;
    int max_length = 1;
    int current_length = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    }
    max_length = max(max_length, current_length);
    cout << max_length << endl;
}