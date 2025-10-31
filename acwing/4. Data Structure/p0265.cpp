// https://www.acwing.com/problem/content/267/

#include <bits/stdc++.h>
using namespace std;

const int N = 40010, INF = 1e7;

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
    int n;
    cin >> n;
    int x;
    cin >> x;
    int ans = 0;
    ans += x;
    T.insert(x);
    for (int i = 2; i <= n; i++) {
        cin >> x;
        ans += min(x - T.get_pre(x + 1), T.get_suc(x - 1) - x);
        T.insert(x);
    }
    cout << ans << endl;
    return 0;
}
