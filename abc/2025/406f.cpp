// https://atcoder.jp/contests/abc406/tasks/abc406_f

#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r;
    long long sum;
};

node tree[300005 << 2];

void push_up(int p) { tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum; }

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].sum = 0;
    if (l == r) {
        tree[p].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].sum += v;
        return;
    }
    if (x <= tree[p << 1].r) {
        update(p << 1, x, v);
    } else {
        update(p << 1 | 1, x, v);
    }
    push_up(p);
}

long long query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }

    long long sum = 0;

    if (l <= tree[p << 1].r) {
        sum += query(p << 1, l, r);
    }
    if (r >= tree[p << 1 | 1].l) {
        sum += query(p << 1 | 1, l, r);
    }
    return sum;
}

int n;
int u[300005], v[300005];
vector<int> g[300005];

int timer = 0, in[300005], out[300005];

int depth[300005];

void dfs(int x, int parent) {
    depth[x] = depth[parent] + 1;
    in[x] = ++timer;
    for (auto y : g[x]) {
        if (y == parent) continue;
        dfs(y, x);
    }
    out[x] = timer;
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs(1, 0);

    build(1, 1, n);

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, w;
            cin >> x >> w;
            update(1, in[x], w);
        } else {
            int y;
            cin >> y;
            if (depth[u[y]] < depth[v[y]])
                y = v[y];
            else
                y = u[y];
            long long p1 = query(1, in[y], out[y]);
            long long q1 = tree[1].sum - p1;
            cout << labs(p1 - q1) << endl;
        }
    }

    return 0;
}