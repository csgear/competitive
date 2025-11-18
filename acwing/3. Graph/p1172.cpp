// https://www.acwing.com/problem/content/1174/
// 1172. 祖孙询问

#include <bits/stdc++.h>
using namespace std;

const int N = 40010, M = 80010, LOG = 16;

struct Edge {
    int to, next;
} edges[M];

int head[N], idx = -1;
int depth[N], fa[N][LOG + 1];
int root;
int n, m;

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

void dfs(int u, int father) {
    depth[u] = depth[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= LOG; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (v == father) continue;
        dfs(v, u);
    }
};

void bfs(int root) {
    queue<int> q;
    q.push(root);
    depth[root] = 1;
    fa[root][0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= LOG; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (depth[v]) continue;
            depth[v] = depth[u] + 1;
            fa[v][0] = u;
            q.push(v);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    // Make a and b at the same depth
    for (int i = LOG; i >= 0; i--) {
        if (depth[fa[a][i]] >= depth[b]) {
            a = fa[a][i];
        }
    }

    if (a == b) return a;

    // Binary lift to find LCA
    for (int i = LOG; i >= 0; i--) {
        // If jumping by 2^i would go beyond the root,
        // both become 0, the condition is false
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }

    return fa[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);

    depth[0] = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        if (v == -1) {
            root = u;
        } else {
            add_edge(u, v);
            add_edge(v, u);
        }
    }

    // dfs(root, 0);

    bfs(root);

    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        if (p == x)
            cout << "1" << endl;
        else if (p == y)
            cout << "2" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}