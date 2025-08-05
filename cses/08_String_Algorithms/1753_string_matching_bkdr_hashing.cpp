// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int BASE = 131;

// Note: experimmental code for string matching using BKDR hashing
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    if (m > n) {
        cout << 0 << '\n';
        return 0;
    }

    ull pattern_hash = 0;
    ull power = 1;
    for (int i = 0; i < m; i++) {
        pattern_hash += t[i] * power;
        if (i < m - 1) power *= BASE;
    }

    ull text_hash = 0;
    ull curr_power = 1;

    for (int i = 0; i < m; i++) {
        text_hash += s[i] * curr_power;
        if (i < m - 1) curr_power *= BASE;
    }

    int count = 0;
    if (text_hash == pattern_hash) count++;

    for (int i = m; i < n; i++) {
        text_hash -= s[i - m];
        text_hash /= BASE;

        text_hash += s[i] * power;

        if (text_hash == pattern_hash) count++;
    }

    cout << count << '\n';
    return 0;
}
