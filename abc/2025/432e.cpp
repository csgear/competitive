// https://atcoder.jp/contests/abc432/tasks/abc432_e
// E - Clamp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

struct BIT {
    ll tree[MAXN];
    inline int lowbit(int x) { return x & (-x); }

    void add(int p, int d) {
        ++p;
        for (; p < MAXN; p += lowbit(p)) {
            tree[p] += d;
        }
    }

    ll qry(int p) {
        ++p;
        ll res = 0;
        for (; p; p -= lowbit(p)) {
            res += tree[p];
        }
        return res;
    }
} b1, bs;

int a[MAXN], n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b1.add(a[i], 1);
        bs.add(a[i], a[i]);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            b1.add(a[x], -1);
            bs.add(a[x], -a[x]);
            a[x] = y;
            b1.add(a[x], 1);
            bs.add(a[x], a[x]);
        } else {
            int l, r;
            cin >> l >> r;
            if (l >= r) {
                cout << 1ll * n * l << "\n";
                continue;
            }
            ll t1 = b1.qry(l - 1);
            ll t2 = n - b1.qry(r);
            ll ans = bs.qry(r) - bs.qry(l - 1);
            ans += t1 * l + t2 * r;
            cout << ans << "\n";
        }
    }
}