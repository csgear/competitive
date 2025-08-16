// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2];
ll lazy[N << 2];

void push_up(ll p) { tree[p] = min(tree[p << 1], tree[p << 1 | 1]); }

void build(ll p, ll pl, ll pr) {
    lazy[p] = 0;
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void apply_lazy(ll p, ll pl, ll pr, ll d) {
    lazy[p] += d;
    tree[p] += d;
}

void push_down(ll p, ll pl, ll pr) {
    if (lazy[p]) {
        ll mid = (pl + pr) >> 1;
        apply_lazy(p << 1, pl, mid, lazy[p]);
        apply_lazy(p << 1 | 1, mid + 1, pr, lazy[p]);
        lazy[p] = 0;
    }
}

void update(ll L, ll R, ll p, ll pl, ll pr, ll val) {
    if (L <= pl && pr <= R) {
        apply_lazy(p, pl, pr, val);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        update(L, R, p << 1, pl, mid, val);
    }
    if (R > mid) {
        update(L, R, p << 1 | 1, mid + 1, pr, val);
    }
    push_up(p);
}

void point_set(ll pos, ll val, ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = val;
        lazy[p] = 0;
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_set(pos, val, p << 1, pl, mid);
    else
        point_set(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p);
}

ll query(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    push_down(p, pl, pr);
    ll res = LLONG_MAX;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res = min(res, query(L, R, p << 1, pl, mid));
    }
    if (R > mid) {
        res = min(res, query(L, R, p << 1 | 1, mid + 1, pr));
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
            int k, u;
            cin >> k >> u;
            point_set(k, u, 1, 1, n);
            a[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a, b, 1, 1, n) << '\n';
        }
    }
    return 0;
}