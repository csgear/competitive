// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    int odd_count = 0;
    char odd_char = 'A';

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            odd_count++;
            odd_char = 'A' + i;
        }
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    vector<char> result;
    result.reserve(s.size());

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            int count = freq[i] / 2;
            for (int j = 0; j < count; j++) {
                result.push_back('A' + i);
            }
        }
    }

    if (odd_count == 1) {
        result.push_back(odd_char);
    }

    for (int i = 25; i >= 0; i--) {
        if (freq[i] > 0) {
            int count = freq[i] / 2;
            for (int j = 0; j < count; j++) {
                result.push_back('A' + i);
            }
        }
    }

    string palindrome(result.begin(), result.end());
    cout << palindrome << endl;

    return 0;
}