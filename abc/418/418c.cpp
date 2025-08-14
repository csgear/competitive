// https://atcoder.jp/contests/abc418/tasks/abc418_c

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3e5 + 5;

ll q, n, a[MAXN], sm[MAXN];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        sm[i] = sm[i - 1] + a[i];
    }

    while (q--) {
        ll b, ans;
        cin >> b;
        // Find first position where a[i] >= b-1
        int p = lower_bound(a + 1, a + n + 1, b - 1) - a;
        // pigon hole theorem:
        // sum of elements < b-1 + count of elements >= b-1 multiplied by (b-1) + 1
        ans = sm[p - 1] + (n - p + 1) * (b - 1) + 1;
        if (ans > sm[n]) ans = -1;
        cout << ans << endl;
    }
    return 0;
}