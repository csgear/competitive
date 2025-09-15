// https://www.luogu.com.cn/problem/P3948

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5 + 5;

LL n, opt, mod, minn, maxx, l, r, x, f;

LL d[N], anss[N];

int query(LL l, LL r) {
    LL ans = 0;
    LL t = 0;
    for (int i = 1; i <= r; i++) {
        t += d[i];
        if (i >= l && (t * i) % mod >= minn && (t * i) % mod <= maxx) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> opt >> mod >> minn >> maxx;
    while (opt--) {
        char op;
        cin >> op;
        if (op == 'A') {
            cin >> l >> r >> x;
            d[l] += x;
            d[r + 1] -= x;
        } else {
            cin >> l >> r;
            cout << query(l, r) << "\n";
        }
    }
    LL t = 0;
    for (int i = 1; i <= n; i++) {
        t += d[i];
        anss[i] = (t * i) % mod <= maxx && (t * i) % mod >= minn ? 1 : 0;
        anss[i] += anss[i - 1];
    }
    cin >> f;

    while (f--) {
        cin >> l >> r;
        cout << anss[r] - anss[l - 1] << "\n";
    }

    return 0;
}