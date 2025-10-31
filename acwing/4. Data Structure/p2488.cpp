// https://www.acwing.com/problem/content/description/2490/

#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
const int INF = 1e9;

struct Node {
    int l, r;
    multiset<int> s;
} tree[N << 2];

int n, m;

int w[N];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].s.insert(-INF);
    tree[p].s.insert(INF);

    if (l == r) {
        tree[p].s.insert(w[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);

    // Merge from children
    for (int x : tree[p << 1].s) {
        if (x != -INF && x != INF) tree[p].s.insert(x);
    }
    for (int x : tree[p << 1 | 1].s) {
        if (x != -INF && x != INF) tree[p].s.insert(x);
    }
}

void update(int p, int pos, int val) {
    // erase 1 value, not all values
    tree[p].s.erase(tree[p].s.find(w[pos]));
    tree[p].s.insert(val);
    if (tree[p].l == tree[p].r) {
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (pos <= mid) {
        update(p << 1, pos, val);
    } else {
        update(p << 1 | 1, pos, val);
    }
}

int query(int p, int l, int r, int x) {
    if (tree[p].l >= l && tree[p].r <= r) {
        auto it = tree[p].s.lower_bound(x);
        --it;
        return *it;
    }

    int mid = (tree[p].l + tree[p].r) >> 1;
    int res = -INF;
    if (l <= mid) {
        res = max(res, query(p << 1, l, r, x));
    }
    if (r > mid) {
        res = max(res, query(p << 1 | 1, l, r, x));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> w[i];

    build(1, 1, n);

    while (m--) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> x;
            update(1, l, x);
            w[l] = x;
        } else {
            cin >> l >> r >> x;
            cout << query(1, l, r, x) << '\n';
        }
    }
    return 0;
}