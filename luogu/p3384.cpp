// https://www.luogu.com.cn/problem/P3384

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000005;
int n, m, root, MOD;
int arr[MAXN];

int head[MAXN], cnt = 1;

struct Edge {
    int to, nxt;
} edges[MAXN * 2];

ll tree[MAXN * 4], tag[MAXN * 4];

int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], id[MAXN], idx = 0;

void addEdge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

void dfs1(int u, int parent) {
    fa[u] = parent;
    dep[u] = dep[parent] + 1;
    sz[u] = 1;
    son[u] = -1;

    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;
        if (v == parent) continue;

        dfs1(v, u);
        sz[u] += sz[v];

        if (son[u] == -1 || sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int topf) {
    top[u] = topf;
    dfn[u] = ++idx;
    id[idx] = u;

    if (son[u] != -1) {
        dfs2(son[u], topf);
    }

    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void push_up(ll p) { tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % MOD; }

void add_tag(ll p, ll pl, ll pr, ll d) {
    tag[p] = (tag[p] + d) % MOD;
    tree[p] = (tree[p] + d * (pr - pl + 1)) % MOD;
}

void push_down(ll p, ll pl, ll pr) {
    if (tag[p]) {
        ll mid = (pl + pr) >> 1;
        add_tag(p << 1, pl, mid, tag[p]);
        add_tag(p << 1 | 1, mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}

void build(ll p, ll pl, ll pr) {
    tag[p] = 0;
    if (pl == pr) {
        tree[p] = arr[id[pl]] % MOD;
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void update(ll L, ll R, ll p, ll pl, ll pr, ll val) {
    if (L <= pl && pr <= R) {
        add_tag(p, pl, pr, val);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        update(L, R, p << 1, pl, mid, val);
    }
    if (R > mid) {
        update(L, R, p << 1 | 1, mid + 1, pr, val);
    }
    push_up(p);
}

ll query(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    push_down(p, pl, pr);
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res = (res + query(L, R, p << 1, pl, mid)) % MOD;
    }
    if (R > mid) {
        res = (res + query(L, R, p << 1 | 1, mid + 1, pr)) % MOD;
    }
    return res;
}

void pathAdd(int u, int v, ll val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(dfn[top[u]], dfn[u], 1, 1, n, val);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(dfn[u], dfn[v], 1, 1, n, val);
}

void subtreeAdd(int u, ll val) { update(dfn[u], dfn[u] + sz[u] - 1, 1, 1, n, val); }

ll pathSum(int u, int v) {
    ll sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        sum = (sum + query(dfn[top[u]], dfn[u], 1, 1, n)) % MOD;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    sum = (sum + query(dfn[u], dfn[v], 1, 1, n)) % MOD;
    return sum;
}

ll subtreeSum(int u) { return query(dfn[u], dfn[u] + sz[u] - 1, 1, 1, n); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> root >> MOD;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs1(root, 0);
    dfs2(root, root);
    build(1, 1, n);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            // Path add
            int x, y;
            ll z;
            cin >> x >> y >> z;
            pathAdd(x, y, z);
        } else if (op == 2) {
            // Path sum
            int x, y;
            cin >> x >> y;
            cout << pathSum(x, y) << '\n';
        } else if (op == 3) {
            // Subtree add
            int x;
            ll z;
            cin >> x >> z;
            subtreeAdd(x, z);
        } else {
            // Subtree sum
            int x;
            cin >> x;
            cout << subtreeSum(x) << '\n';
        }
    }

    return 0;
}