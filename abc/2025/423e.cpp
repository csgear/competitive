// https://atcoder.jp/contests/abc423/tasks/abc423_e

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3e5 + 5;

ll a[MAXN], s1[MAXN], s2[MAXN], s3[MAXN];

int main() {
    int n, q;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + a[i] * i;
        s3[i] = s3[i - 1] + a[i] * i * i;
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        ans -= (r + 1) * (l - 1) * (s1[r] - s1[l - 1]);
        ans += (l + r) * (s2[r] - s2[l - 1]);
        ans -= (s3[r] - s3[l - 1]);
        cout << ans << "\n";
    }

    return 0;
}