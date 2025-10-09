// https://atcoder.jp/contests/abc426/tasks/abc426_f

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 300010;

LL a[N];

struct node {
    int l, r;
    LL minn, lazy, cnt;
} tr[N << 2];

void push_up(int p) {
    tr[p].minn = min(tr[p << 1].minn, tr[p << 1 | 1].minn);
    tr[p].cnt = tr[p << 1].cnt + tr[p << 1 | 1].cnt;
}

void push_down(int p) {
    if (tr[p].lazy) {
        LL lazy = tr[p].lazy;
        tr[p << 1].minn -= lazy;
        tr[p << 1 | 1].minn -= lazy;
        tr[p << 1].lazy += lazy;
        tr[p << 1 | 1].lazy += lazy;
        tr[p].lazy = 0;
    }
}

void build(int p, int l, int r) {
    tr[p].l = l, tr[p].r = r;
    tr[p].lazy = 0;
    if (l == r) {
        tr[p].minn = a[l];
        tr[p].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

LL update_and_query(int L, int R, int p, LL k) {
    if (tr[p].cnt == 0) return 0;

    if (L <= tr[p].l && tr[p].r <= R && tr[p].minn > k) {
        tr[p].minn -= k;
        tr[p].lazy += k;
        return tr[p].cnt * k;
    }

    if (tr[p].l == tr[p].r) {
        LL res = tr[p].minn;
        tr[p].cnt = 0;
        tr[p].minn = 1e18;
        return res;
    }

    push_down(p);

    LL res = 0;
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (L <= mid) res += update_and_query(L, R, p << 1, k);
    if (R > mid) res += update_and_query(L, R, p << 1 | 1, k);
    push_up(p);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << update_and_query(l, r, 1, k) << "\n";
    }
    return 0;
}