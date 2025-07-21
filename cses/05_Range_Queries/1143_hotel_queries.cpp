// https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
ll a[N];
ll tree[N << 2];

void push_up(ll p) { tree[p] = max(tree[p << 1], tree[p << 1 | 1]); }

void build(ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void point_update(ll pos, ll val, ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = val;
        a[pos] = val;
        return;
    }
    ll mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_update(pos, val, p << 1, pl, mid);
    else
        point_update(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p);
}

ll find_first(ll p, ll pl, ll pr, ll val) {
    if (tree[p] < val) {
        return 0;
    }
    if (pl == pr) {
        return pl;
    }

    ll mid = (pl + pr) >> 1;
    if (tree[p << 1] >= val) {
        return find_first(p << 1, pl, mid, val);
    }
    return find_first(p << 1 | 1, mid + 1, pr, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        ll hotel_idx = find_first(1, 1, n, r);
        cout << hotel_idx << (i == m - 1 ? "" : " ");
        if (hotel_idx != 0) {
            point_update(hotel_idx, a[hotel_idx] - r, 1, 1, n);
        }
    }
    cout << "\n";

    return 0;
}