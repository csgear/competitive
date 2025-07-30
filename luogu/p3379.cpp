// https://www.luogu.com.cn/problem/P3379

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

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] <= dep[top[v]]) {
            v = fa[top[v]];
        } else {
            u = fa[top[u]];
        }
    }
    return dep[u] <= dep[v] ? u : v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> root;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(root, 0);
    dfs2(root, root);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}