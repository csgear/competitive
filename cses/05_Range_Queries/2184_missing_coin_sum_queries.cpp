// https://cses.fi/problemset/task/2184

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2][30];
ll sm[N][30];

void push_up(ll p) {
    for (int i = 0; i < 30; i++) {
        tree[p][i] = min(tree[p << 1][i], tree[p << 1 | 1][i]);
    }
}

void build(ll p, ll pl, ll pr) {
    for (int i = 0; i < 30; i++) {
        tree[p][i] = 2e9;
    }
    if (pl == pr) {
        if (a[pl] > 0) {
            int bit = __builtin_clzll(1) - __builtin_clzll(a[pl]);
            tree[p][bit] = a[pl];
        }
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void query(ll L, ll R, ll p, ll pl, ll pr, ll result[30]) {
    if (L <= pl && pr <= R) {
        for (int i = 0; i < 30; i++) {
            result[i] = min(result[i], tree[p][i]);
        }
        return;
    }
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        query(L, R, p << 1, pl, mid, result);
    }
    if (R > mid) {
        query(L, R, p << 1 | 1, mid + 1, pr, result);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            int bit = __builtin_clzll(1) - __builtin_clzll(a[i]);
            sm[i][bit] = a[i];
        }
    }

    // Build prefix sums
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            sm[i][j] += sm[i - 1][j];
        }
    }

    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        ll result[30];
        for (int i = 0; i < 30; i++) {
            result[i] = 2e9;
        }
        query(l, r, 1, 1, n, result);

        ll tot = 0, ans = -1;
        for (int i = 0; i < 30; i++) {
            if (tot + 1 < (1LL << (i + 1)) && result[i] > tot + 1) {
                ans = tot + 1;
                break;
            }
            tot += sm[r][i] - sm[l - 1][i];
        }
        cout << (ans == -1 ? tot + 1 : ans) << "\n";
    }

    return 0;
}