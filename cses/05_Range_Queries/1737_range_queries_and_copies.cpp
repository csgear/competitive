// https://cses.fi/problemset/task/1737
// 主席树

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
const int MAXT = MAXN * 25;

int arr[MAXN], root[MAXN], lc[MAXT], rc[MAXT];
ll sm[MAXT];

int cnt = 0;
int version = 0;

int clone(int p) {
    int rt = ++cnt;
    sm[rt] = sm[p];
    lc[rt] = lc[p];
    rc[rt] = rc[p];
    return rt;
}

int build(int pl, int pr) {
    int rt = ++cnt;
    if (pl == pr) {
        sm[rt] = arr[pl];
        return rt;
    }
    int mid = (pl + pr) / 2;
    lc[rt] = build(pl, mid);
    rc[rt] = build(mid + 1, pr);
    sm[rt] = sm[lc[rt]] + sm[rc[rt]];
    return rt;
}

int update(int p, int pl, int pr, int pos, ll val) {
    int rt = ++cnt;
    lc[rt] = lc[p];
    rc[rt] = rc[p];

    if (pl == pr) {
        sm[rt] = val;
        return rt;
    }

    int mid = (pl + pr) / 2;
    if (pos <= mid) {
        lc[rt] = update(lc[p], pl, mid, pos, val);
    } else {
        rc[rt] = update(rc[p], mid + 1, pr, pos, val);
    }
    sm[rt] = sm[lc[rt]] + sm[rc[rt]];
    return rt;
}

ll query(int L, int R, int p, int pl, int pr) {
    if (pl > R || pr < L) {
        return 0;
    }
    if (pl >= L && pr <= R) {
        return sm[p];
    }
    int mid = (pl + pr) / 2;
    return query(L, R, lc[p], pl, mid) + query(L, R, rc[p], mid + 1, pr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    root[1] = build(1, n);
    version = 1;

    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int t, k, v;
            cin >> t >> k >> v;
            root[t] = update(root[t], 1, n, k, v);
        } else if (op == 2) {
            int t, l, r;
            cin >> t >> l >> r;
            cout << query(l, r, root[t], 1, n) << "\n";
        } else if (op == 3) {
            int t;
            cin >> t;
            root[++version] = clone(root[t]);
        }
    }

    return 0;
}