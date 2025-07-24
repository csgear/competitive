// https://cses.fi/problemset/task/1190

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
        update(1, 1, n, l, r);
        cout << tree[1].maxv << '\n';
    }
    return 0;
}