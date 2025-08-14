// https://cses.fi/problemset/task/1736

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2];
ll lazy_a[N << 2];  // constant term (base value)
ll lazy_d[N << 2];  // linear term (arithmetic progression count)

void push_up(ll p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

void build(ll p, ll pl, ll pr) {
    lazy_a[p] = lazy_d[p] = 0;
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void apply_lazy(ll p, ll pl, ll pr, ll d0, ll d1) {
    ll len = pr - pl + 1;
    lazy_a[p] += d0;
    lazy_d[p] += d1;
    // d0 * len: constant term contribution
    // d1 * len * (len-1) / 2: arithmetic progression 0,1,2,...,(len-1)
    tree[p] += d0 * len + d1 * len * (len - 1) / 2;
}

void push_down(ll p, ll pl, ll pr) {
    if (lazy_a[p] || lazy_d[p]) {
        ll mid = (pl + pr) >> 1;
        ll left_len = mid - pl + 1;

        // Push to left child
        apply_lazy(p << 1, pl, mid, lazy_a[p], lazy_d[p]);

        // Push to right child: base shifts by left_len positions
        apply_lazy(p << 1 | 1, mid + 1, pr, lazy_a[p] + lazy_d[p] * left_len, lazy_d[p]);

        lazy_a[p] = lazy_d[p] = 0;
    }
}

void update(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        // For arithmetic progression 1,2,3,... starting at L
        // This segment [pl,pr] gets values starting at (pl - L + 1)
        ll start_val = pl - L + 1;
        apply_lazy(p, pl, pr, start_val, 1);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        update(L, R, p << 1, pl, mid);
    }
    if (R > mid) {
        update(L, R, p << 1 | 1, mid + 1, pr);
    }
    push_up(p);
}

ll query(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    push_down(p, pl, pr);
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res += query(L, R, p << 1, pl, mid);
    }
    if (R > mid) {
        res += query(L, R, p << 1 | 1, mid + 1, pr);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            cin >> l >> r;
            update(l, r, 1, 1, n);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 1, n) << '\n';
        }
    }

    return 0;
}
