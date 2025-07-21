// https://cses.fi/problemset/task/2166

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll sum_t[N << 2];
ll pre_t[N << 2];

void push_up(int p) {
    sum_t[p] = sum_t[p << 1] + sum_t[p << 1 | 1];
    pre_t[p] = max(pre_t[p << 1], sum_t[p << 1] + pre_t[p << 1 | 1]);
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        sum_t[p] = a[pl];
        pre_t[p] = max(a[pl], 0LL);
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void point_set(int pos, ll val, int p, int pl, int pr) {
    if (pl == pr) {
        sum_t[p] = val;
        pre_t[p] = max(val, 0LL);
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
pair<ll, ll> query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        return {sum_t[p], pre_t[p]};
    }
    int mid = (pl + pr) >> 1;
    if (R <= mid) return query(L, R, p << 1, pl, mid);
    if (L > mid) return query(L, R, p << 1 | 1, mid + 1, pr);
    auto left = query(L, mid, p << 1, pl, mid);
    auto right = query(mid + 1, R, p << 1 | 1, mid + 1, pr);
    ll total_sum = left.first + right.first;
    ll max_pre = max(left.second, left.first + right.second);
    return {total_sum, max_pre};
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
            cout << query(l, r, 1, 1, n).second << '\n';
        }
    }
    return 0;
}