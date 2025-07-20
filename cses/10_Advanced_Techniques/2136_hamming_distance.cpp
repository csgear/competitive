// https://cses.fi/problemset/task/2136

#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; ++j) {
            if (s[j] == '1') {
                b[i] |= 1 << j;
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = min(ans, __builtin_popcount(b[i] ^ b[j]));
        }
    }
    cout << ans << '\n';
    return 0;
}