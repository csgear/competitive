// https://atcoder.jp/contests/abc403/tasks/abc403_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, u;
    cin >> t >> u;

    int m = t.size();
    int n = u.size();

    bool ans = false;
    for (int i = 0; i < m - n + 1; i++) {
        int j = 0;
        for (; j < n; j++) {
            if (t[i + j] != u[j] && t[i + j] != '?') {
                break;
            }
        }
        if (j == n) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
