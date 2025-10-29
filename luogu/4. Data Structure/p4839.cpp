// https://www.luogu.com.cn/problem/P4839

#include <bits/stdc++.h>
using namespace std;
const int BIT = 30;

const int N = 5e4 + 5;

int tree[N << 2][BIT + 1], b[BIT + 1];

int n, m;

bool insert(int basis[], int v) {
    for (int i = BIT; i >= 0; i--) {
        if (v & (1 << i)) {
            if (!basis[i]) {
                basis[i] = v;
                return true;
            }
            v ^= basis[i];
        }
    }
    return false;
}

void add(int p, int pl, int pr, int pos, int v) {
    insert(tree[p], v);
    int mid = (pl + pr) >> 1;
    if (pl < pr) {
        if (pos <= mid)
            add(p << 1, pl, mid, pos, v);
        else
            add(p << 1 | 1, mid + 1, pr, pos, v);
    }
}

void merge(int p, int pl, int pr, int ql, int qr) {
    if (ql <= pl && pr <= qr) {
        for (int i = 0; i <= BIT; i++) {
            if (tree[p][i]) {
                insert(b, tree[p][i]);
            }
        }
        return;
    }

    int mid = (pl + pr) >> 1;
    if (ql <= mid) {
        merge(p << 1, pl, mid, ql, qr);
    }
    if (mid < qr) {
        merge(p << 1 | 1, mid + 1, pr, ql, qr);
    }
}

int query(int p, int pl, int pr, int ql, int qr) {
    memset(b, 0, sizeof(b));
    merge(1, 1, m, ql, qr);
    int ans = 0;
    for (int i = BIT; i >= 0; i--) {
        if ((ans ^ b[i]) > ans) {
            ans ^= b[i];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos, v;
            cin >> pos >> v;
            add(1, 1, m, pos, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, m, l, r) << "\n";
        }
    }
    return 0;
}