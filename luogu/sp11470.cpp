// https://www.luogu.com.cn/problem/SP11470
// SP11470 TTM - To the moon

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
const int MAXT = MAXN * 70;

int root[MAXN], lc[MAXT], rc[MAXT], lazy[MAXT];
ll arr[MAXN], sm[MAXT];

int n, m, t = 0, cnt = 0;

int clone(int p) {
    int rt = ++cnt;
    sm[rt] = sm[p];
    lazy[rt] = lazy[p];
    lc[rt] = lc[p];
    rc[rt] = rc[p];
    return rt;
}

void up(int p) { sm[p] = sm[lc[p]] + sm[rc[p]]; }

void apply_lazy(int p, int d, int ln) {
    sm[p] += d * ln;
    lazy[p] += d;
}

void down(int p, int ln, int rn) {
    if (lazy[p]) {
        lc[p] = clone(lc[p]);
        rc[p] = clone(rc[p]);
        apply_lazy(lc[p], lazy[p], ln);
        apply_lazy(rc[p], lazy[p], rn);
        lazy[p] = 0;
    }
}

int build(int pl, int pr) {
    int rt = ++cnt;
    lazy[rt] = 0;

    if (pl == pr) {
        sm[rt] = arr[pl];
    } else {
        int mid = (pl + pr) / 2;
        lc[rt] = build(pl, mid);
        rc[rt] = build(mid + 1, pr);
        up(rt);
    }
    return rt;
}

int update(int L, int R, int p, int pl, int pr, int d) {
    int rt = clone(p);
    if (L <= pl && pr <= R) {
        apply_lazy(rt, d, pr - pl + 1);
    } else {
        int mid = (pl + pr) / 2;
        down(rt, mid - pl + 1, pr - mid);
        if (L <= mid) lc[rt] = update(L, R, lc[rt], pl, mid, d);
        if (R > mid) rc[rt] = update(L, R, rc[rt], mid + 1, pr, d);
        up(rt);
    }
    return rt;
}

ll query(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) {
        return sm[p];
    }
    int mid = (pl + pr) / 2;
    down(p, mid - pl + 1, pr - mid);
    ll ans = 0;
    if (L <= mid) ans += query(L, R, lc[p], pl, mid);
    if (R > mid) ans += query(L, R, rc[p], mid + 1, pr);
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    root[0] = build(1, n);
    char op;
    while (m--) {
        cin >> op;
        if (op == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            root[t + 1] = update(l, r, root[t], 1, n, d);
            t++;
        } else if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, root[t], 1, n) << '\n';
        } else if (op == 'H') {
            int l, r, t1;
            cin >> l >> r >> t1;
            cout << query(l, r, root[t1], 1, n) << '\n';
        } else if (op == 'B') {
            int x;
            cin >> x;
            t = x;
        }
    }
}
