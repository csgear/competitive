// https://cses.fi/problemset/task/3226

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5 + 5;

struct TreeNode {
    ll sum, pre, suf, maxv;
} tree[MAXN << 2];

ll a[MAXN];

void push_up(int p) {
    auto left = tree[p << 1];
    auto right = tree[p << 1 | 1];
    tree[p] = {left.sum + right.sum, max(left.pre, left.sum + right.pre),
               max(right.suf, left.suf + right.sum),
               max({left.maxv, right.maxv, left.suf + right.pre})};
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        ll v = a[pl];
        tree[p] = {v, max(v, 0LL), max(v, 0LL), max(v, 0LL)};
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void update(int p, int pl, int pr, int pos, ll val) {
    if (pl == pr) {
        tree[p] = {val, max(val, 0LL), max(val, 0LL), max(val, 0LL)};
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        update(p << 1, pl, mid, pos, val);
    else
        update(p << 1 | 1, mid + 1, pr, pos, val);
    push_up(p);
}

TreeNode query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return tree[p];
    int mid = (pl + pr) >> 1;
    if (R <= mid) return query(L, R, p << 1, pl, mid);
    if (L > mid) return query(L, R, p << 1 | 1, mid + 1, pr);
    auto left = query(L, R, p << 1, pl, mid);
    auto right = query(L, R, p << 1 | 1, mid + 1, pr);
    TreeNode res;
    res.sum = left.sum + right.sum;
    res.pre = max(left.pre, left.sum + right.pre);
    res.suf = max(right.suf, right.sum + left.suf);
    res.maxv = max({left.maxv, right.maxv, left.suf + right.pre});
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto res = query(l, r, 1, 1, n);
        cout << res.maxv << '\n';
    }
    return 0;
}