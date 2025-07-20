// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2];
ll tag[N << 2];

void push_up(ll p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

void build(ll p, ll pl, ll pr) {
    tag[p] = 0;
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void add_tag(ll p, ll pl, ll pr, ll d) {
    tag[p] += d;
    tree[p] += d * (pr - pl + 1);
}

void push_down(ll p, ll pl, ll pr) {
    if (tag[p]) {
        ll mid = (pl + pr) >> 1;
        add_tag(p << 1, pl, mid, tag[p]);
        add_tag(p << 1 | 1, mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}

void update(ll L, ll R, ll p, ll pl, ll pr, ll d) {
    if (L <= pl && pr <= R) {
        add_tag(p, pl, pr, d);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        update(L, R, p << 1, pl, mid, d);
    }
    if (R > mid) {
        update(L, R, p << 1 | 1, mid + 1, pr, d);
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
            int a, b, v;
            cin >> a >> b >> v;
            update(a, b, 1, 1, n, v);
        } else {
            int k;
            cin >> k;
            cout << query(k, k, 1, 1, n) << '\n';
        }
    }
    return 0;
}