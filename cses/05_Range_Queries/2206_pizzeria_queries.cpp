// https://cses.fi/problemset/task/2206

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const ll INF = 1e18;

ll p[N];
ll tree[2][N << 2];  // tree[0] = left, tree[1] = right

void push_up(int type, ll p) { tree[type][p] = min(tree[type][p << 1], tree[type][p << 1 | 1]); }

void build(int type, ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[type][p] = (type == 0) ? (::p[pl] - pl) : (::p[pl] + pl);
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(type, p << 1, pl, mid);
    build(type, p << 1 | 1, mid + 1, pr);
    push_up(type, p);
}

void update(int type, ll pos, ll val, ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[type][p] = (type == 0) ? (val - pos) : (val + pos);
        return;
    }
    ll mid = (pl + pr) >> 1;
    if (pos <= mid)
        update(type, pos, val, p << 1, pl, mid);
    else
        update(type, pos, val, p << 1 | 1, mid + 1, pr);
    push_up(type, p);
}

ll query(int type, ll L, ll R, ll p, ll pl, ll pr) {
    if (L > R) return INF;
    if (L <= pl && pr <= R) {
        return tree[type][p];
    }
    ll res = INF;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res = min(res, query(type, L, R, p << 1, pl, mid));
    }
    if (R > mid) {
        res = min(res, query(type, L, R, p << 1 | 1, mid + 1, pr));
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
        cin >> p[i];
    }

    build(0, 1, 1, n);
    build(1, 1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, x;
            cin >> k >> x;
            p[k] = x;
            update(0, k, x, 1, 1, n);
            update(1, k, x, 1, 1, n);
        } else {
            int k;
            cin >> k;

            // Case 1: pizzeria at position <= k
            ll min_left = query(0, 1, k, 1, 1, n) + k;

            // Case 2: pizzeria at position >= k
            ll min_right = query(1, k, n, 1, 1, n) - k;

            cout << min(min_left, min_right) << '\n';
        }
    }

    return 0;
}