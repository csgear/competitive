// https://www.luogu.com.cn/problem/P3919
// P3919 【模板】可持久化线段树 1（可持久化数组）

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
const int MAXT = MAXN * 23;

int arr[MAXN], root[MAXN], lchild[MAXT], rchild[MAXT], value[MAXT];

int cnt = 0;

int build(int pl, int pr) {
    int rt = ++cnt;
    if (pl == pr) {
        value[rt] = arr[pl];
        return rt;
    }
    int mid = (pl + pr) / 2;
    lchild[rt] = build(pl, mid);
    rchild[rt] = build(mid + 1, pr);
    return rt;
}

int update(int p, int pl, int pr, int pos, ll val) {
    int rt = ++cnt;
    lchild[rt] = lchild[p];
    rchild[rt] = rchild[p];
    value[rt] = value[p];

    if (pl == pr) {
        value[rt] = val;
        return rt;
    }

    int mid = (pl + pr) / 2;
    if (pos <= mid) {
        lchild[rt] = update(lchild[p], pl, mid, pos, val);
    } else {
        rchild[rt] = update(rchild[p], mid + 1, pr, pos, val);
    }
    return rt;
}

ll query(int p, int pl, int pr, int pos) {
    if (pl == pr) {
        return value[p];
    }
    int mid = (pl + pr) / 2;
    if (pos <= mid) {
        return query(lchild[p], pl, mid, pos);
    } else {
        return query(rchild[p], mid + 1, pr, pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    root[0] = build(1, n);

    for (int i = 1; i <= m; i++) {
        int v, op;
        cin >> v >> op;
        if (op == 1) {
            int pos;
            ll val;
            cin >> pos >> val;
            root[i] = update(root[v], 1, n, pos, val);
        } else {
            int pos;
            cin >> pos;
            root[i] = root[v];
            cout << query(root[i], 1, n, pos) << "\n";
        }
    }

    return 0;
}