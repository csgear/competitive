// https://cses.fi/problemset/task/2166

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TreeNode {
    ll sum;  // Range sum
    ll pre;  // Maximum prefix sum

    TreeNode() : sum(0), pre(0) {}
    TreeNode(ll s, ll p) : sum(s), pre(p) {}
};

const int N = 2e5 + 5;
ll a[N];
TreeNode tree[N << 2];

void push_up(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].pre = max(tree[p << 1].pre, tree[p << 1].sum + tree[p << 1 | 1].pre);
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        tree[p].sum = a[pl];
        tree[p].pre = max(a[pl], 0LL);
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void point_set(int pos, ll val, int p, int pl, int pr) {
    if (pl == pr) {
        tree[p].sum = val;
        tree[p].pre = max(val, 0LL);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_set(pos, val, p << 1, pl, mid);
    else
        point_set(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p);
}

// L, R: The query range (the interval you want to get the answer for).
// p: The current node in the segment tree.
// pl, pr: The range that the current node p covers.
TreeNode query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    int mid = (pl + pr) >> 1;
    if (R <= mid) return query(L, R, p << 1, pl, mid);
    if (L > mid) return query(L, R, p << 1 | 1, mid + 1, pr);
    auto left = query(L, mid, p << 1, pl, mid);
    auto right = query(mid + 1, R, p << 1 | 1, mid + 1, pr);
    ll total_sum = left.sum + right.sum;
    ll max_pre = max(left.pre, left.sum + right.pre);
    return TreeNode(total_sum, max_pre);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
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
            int k;
            ll u;
            cin >> k >> u;
            point_set(k, u, 1, 1, n);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 1, n).pre << '\n';
        }
    }
    return 0;
}