// https://atcoder.jp/contests/abc420/tasks/abc420_c

#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int N = 2e5 + 5;
LL a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(a[i], b[i]);
    }

    while (q--) {
        char c;
        int x, v;
        cin >> c >> x >> v;
        sum -= min(a[x], b[x]);
        if (c == 'A') {
            a[x] = v;
        } else {
            b[x] = v;
        }
        sum += min(a[x], b[x]);
        cout << sum << endl;
    }

    return 0;
}