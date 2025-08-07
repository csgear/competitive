// https://cses.fi/problemset/task/1733

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nxt(n, 0);

    nxt[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = nxt[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }

    vector<int> periods;
    int j = nxt[n - 1];
    while (j >= 0) {
        periods.push_back(n - (j + 1));
        j = nxt[j];
    }

    periods.push_back(n);

    for (int period : periods) {
        cout << period << " ";
    }
    cout << endl;

    return 0;
}