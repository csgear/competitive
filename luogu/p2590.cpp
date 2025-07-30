// https://www.luogu.com.cn/problem/P2590

// https://www.luogu.com.cn/problem/P3384

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000005;
int n, m, root;
int arr[MAXN];

int head[MAXN], cnt = 1;

struct Edge {
    int to, nxt;
} edges[MAXN * 2];

ll tree[MAXN * 4], maxtree[MAXN * 4];

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

void push_up(ll p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    maxtree[p] = max(maxtree[p << 1], maxtree[p << 1 | 1]);
}

void build(ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = arr[id[pl]];
        maxtree[p] = arr[id[pl]];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

void point_update(ll pos, ll val, ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = val;
        maxtree[p] = val;
        return;
    }
    ll mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_update(pos, val, p << 1, pl, mid);
    else
        point_update(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p);
}

ll query_sum(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res += query_sum(L, R, p << 1, pl, mid);
    }
    if (R > mid) {
        res += query_sum(L, R, p << 1 | 1, mid + 1, pr);
    }
    return res;
}

ll query_max(ll L, ll R, ll p, ll pl, ll pr) {
    if (L <= pl && pr <= R) {
        return maxtree[p];
    }
    ll res = LLONG_MIN;
    ll mid = (pl + pr) >> 1;
    if (L <= mid) {
        res = max(res, query_max(L, R, p << 1, pl, mid));
    }
    if (R > mid) {
        res = max(res, query_max(L, R, p << 1 | 1, mid + 1, pr));
    }
    return res;
}

ll pathSum(int u, int v) {
    ll ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] <= dep[top[v]]) {
            ans += query_sum(dfn[top[v]], dfn[v], 1, 1, n);
            v = fa[top[v]];
        } else {
            ans += query_sum(dfn[top[u]], dfn[u], 1, 1, n);
            u = fa[top[u]];
        }
    }
    ans += query_sum(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, 1, n);
    return ans;
}

ll pathMax(int u, int v) {
    ll ans = LLONG_MIN;
    while (top[u] != top[v]) {
        if (dep[top[u]] <= dep[top[v]]) {
            ans = max(ans, query_max(dfn[top[v]], dfn[v], 1, 1, n));
            v = fa[top[v]];
        } else {
            ans = max(ans, query_max(dfn[top[u]], dfn[u], 1, 1, n));
            u = fa[top[u]];
        }
    }
    ans = max(ans, query_max(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, 1, n));
    return ans;
}

void changeNode(int u, ll val) {
    point_update(dfn[u], val, 1, 1, n);
    arr[u] = val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    root = 1;  // Default root to 1

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dfs1(root, 0);
    dfs2(root, root);
    build(1, 1, n);

    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "QMAX") {
            int u, v;
            cin >> u >> v;
            cout << pathMax(u, v) << '\n';
        } else if (op == "QSUM") {
            int u, v;
            cin >> u >> v;
            cout << pathSum(u, v) << '\n';
        } else if (op == "CHANGE") {
            int u;
            ll t;
            cin >> u >> t;
            changeNode(u, t);
        }
    }

    return 0;
}