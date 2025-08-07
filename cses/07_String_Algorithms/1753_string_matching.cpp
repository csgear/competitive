// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector<int> nxt(m, 0);
    nxt[0] = -1;
    // next[i] stores the length of the longest prefix of t that is also a suffix of t[0..i]
    for (int i = 1, j = -1; i < m; i++) {
        while (j >= 0 && t[i] != t[j + 1]) {
            j = nxt[j];
        }
        if (t[i] == t[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }

    int count = 0;
    for (int i = 0, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != t[j + 1]) {
            j = nxt[j];
        }
        if (s[i] == t[j + 1]) {
            j++;
        }
        if (j == m - 1) {
            count++;
            j = nxt[j];
        }
    }

    cout << count << '\n';
    return 0;
}