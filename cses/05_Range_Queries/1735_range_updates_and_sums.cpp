// https://cses.fi/problemset/task/1735

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2];
ll add_lazy[N << 2];   // for range increment
ll set_lazy[N << 2];   // for range assignment
bool has_set[N << 2];  // flag to check if set operation is pending

void push_up(ll p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

void build(ll p, ll pl, ll pr) {
    add_lazy[p] = 0;
    set_lazy[p] = 0;
    has_set[p] = false;
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void apply_add(ll p, ll pl, ll pr, ll val) {
    add_lazy[p] += val;
    tree[p] += val * (pr - pl + 1);
}

void apply_set(ll p, ll pl, ll pr, ll val) {
    set_lazy[p] = val;
    add_lazy[p] = 0;  // clear add lazy when setting
    has_set[p] = true;
    tree[p] = val * (pr - pl + 1);
}

void push_down(ll p, ll pl, ll pr) {
    ll mid = (pl + pr) >> 1;

    if (has_set[p]) {
        apply_set(p << 1, pl, mid, set_lazy[p]);
        apply_set(p << 1 | 1, mid + 1, pr, set_lazy[p]);
        has_set[p] = false;
        set_lazy[p] = 0;
    }

    if (add_lazy[p]) {
        apply_add(p << 1, pl, mid, add_lazy[p]);
        apply_add(p << 1 | 1, mid + 1, pr, add_lazy[p]);
        add_lazy[p] = 0;
    }
}

void range_add(ll L, ll R, ll p, ll pl, ll pr, ll val) {
    if (L <= pl && pr <= R) {
        apply_add(p, pl, pr, val);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        range_add(L, R, p << 1, pl, mid, val);
    }
    if (R > mid) {
        range_add(L, R, p << 1 | 1, mid + 1, pr, val);
    }
    push_up(p);
}

void range_set(ll L, ll R, ll p, ll pl, ll pr, ll val) {
    if (L <= pl && pr <= R) {
        apply_set(p, pl, pr, val);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        range_set(L, R, p << 1, pl, mid, val);
    }
    if (R > mid) {
        range_set(L, R, p << 1 | 1, mid + 1, pr, val);
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
            ll x;
            cin >> l >> r >> x;
            range_add(l, r, 1, 1, n, x);
        } else if (op == 2) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            range_set(l, r, 1, 1, n, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 1, n) << '\n';
        }
    }
    return 0;
}