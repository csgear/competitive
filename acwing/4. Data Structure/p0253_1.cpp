// https://www.acwing.com/problem/content/255/
// template FHQ treap implementation
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int INF = 1e8;

struct FHQ {
    int lc[N], rc[N], val[N], key[N], sz[N];
    int root, idx;

    int new_node(int v) {
        val[++idx] = v;
        key[idx] = rand();
        sz[idx] = 1;
        lc[idx] = rc[idx] = 0;
        return idx;
    }

    void pushup(int p) { sz[p] = sz[lc[p]] + sz[rc[p]] + 1; }

    // Split by value: <= v goes to x, > v goes to y
    void split(int p, int v, int& x, int& y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (val[p] <= v) {
            x = p;
            split(rc[p], v, rc[p], y);
        } else {
            y = p;
            split(lc[p], v, x, lc[p]);
        }
        pushup(p);
    }

    // Merge two trees: assume max(x) <= min(y)
    int merge(int x, int y) {
        if (!x || !y) return x | y;
        if (key[x] < key[y]) {
            rc[x] = merge(rc[x], y);
            pushup(x);
            return x;
        } else {
            lc[y] = merge(x, lc[y]);
            pushup(y);
            return y;
        }
    }

    void insert(int v) {
        int x, y;
        split(root, v, x, y);
        root = merge(merge(x, new_node(v)), y);
    }

    void erase(int v) {
        int x, y, z;
        split(root, v, x, z);
        split(x, v - 1, x, y);
        // y contains all nodes with value == v
        y = merge(lc[y], rc[y]);  // delete one occurrence
        root = merge(merge(x, y), z);
    }

    int get_rank(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int res = sz[x] + 1;
        root = merge(x, y);
        return res;
    }

    int get_kth(int p, int k) {
        if (!p) return -1;
        if (k <= sz[lc[p]])
            return get_kth(lc[p], k);
        else if (k <= sz[lc[p]] + 1)
            return val[p];
        else
            return get_kth(rc[p], k - sz[lc[p]] - 1);
    }

    int get_pre(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int p = x;
        while (p && rc[p]) p = rc[p];
        int res = p ? val[p] : -INF;
        root = merge(x, y);
        return res;
    }

    int get_suc(int v) {
        int x, y;
        split(root, v, x, y);
        int p = y;
        while (p && lc[p]) p = lc[p];
        int res = p ? val[p] : INF;
        root = merge(x, y);
        return res;
    }
} T;

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    while (m--) {
        int op, x;
        cin >> op >> x;
        if (op == 1)
            T.insert(x);
        else if (op == 2)
            T.erase(x);
        else if (op == 3)
            cout << T.get_rank(x) << '\n';
        else if (op == 4)
            cout << T.get_kth(T.root, x) << '\n';
        else if (op == 5)
            cout << T.get_pre(x) << '\n';
        else if (op == 6)
            cout << T.get_suc(x) << '\n';
    }
    return 0;
}