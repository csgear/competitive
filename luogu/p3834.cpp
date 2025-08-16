// https://www.luogu.com.cn/problem/P3834
// P3834 【模板】可持久化线段树 2

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
const int MAXT = MAXN * 23;

int arr[MAXN], root[MAXN], lc[MAXT], rc[MAXT], sz[MAXT];
vector<int> sorted;
int n, m, cnt = 0;

// build an empty segment tree
int build(int pl, int pr) {
    int rt = ++cnt;
    sz[rt] = 0;
    if (pl < pr) {
        int mid = (pl + pr) / 2;
        lc[rt] = build(pl, mid);
        rc[rt] = build(mid + 1, pr);
    }
    return rt;
}

int insert(int p, int pl, int pr, int pos, int val = 1) {
    int rt = ++cnt;
    lc[rt] = lc[p];
    rc[rt] = rc[p];
    sz[rt] = sz[p] + 1;

    if (pl < pr) {
        int mid = (pl + pr) / 2;
        if (pos <= mid) {
            lc[rt] = insert(lc[p], pl, mid, pos, val);
        } else {
            rc[rt] = insert(rc[p], mid + 1, pr, pos, val);
        }
    }
    return rt;
}

int query(int p0, int p1, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int lsize = sz[lc[p1]] - sz[lc[p0]];
    int mid = (l + r) / 2;
    if (lsize >= k) {
        return query(lc[p0], lc[p1], l, mid, k);
    } else {
        return query(rc[p0], rc[p1], mid + 1, r, k - lsize);
    }
}

void init() {
    cnt = 0;
    sorted.clear();
    for (int i = 1; i <= n; i++) {
        sorted.push_back(arr[i]);
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    auto get_rank = [&](int val) {
        return lower_bound(sorted.begin(), sorted.end(), val) - sorted.begin() + 1;
    };

    root[0] = build(1, sorted.size());
    for (int i = 1; i <= n; i++) {
        int pos = get_rank(arr[i]);
        root[i] = insert(root[i - 1], 1, sorted.size(), pos, 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init();
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int result = query(root[l - 1], root[r], 1, sorted.size(), k);
        cout << sorted[result - 1] << '\n';
    }
    return 0;
}