// https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
const int LOG = 20;

vector<pair<int, int>> adj[MAXN];
int depth[MAXN];
ll dist[MAXN];
int parent[MAXN][LOG];

void dfs(int u, int p, int d, ll w) {
    depth[u] = d;
    dist[u] = w;
    parent[u][0] = p;

    for (auto &[v, weight] : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1, w + weight);
        }
    }
}

void preprocess(int n) {
    dfs(1, -1, 0, 0);

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            } else {
                parent[i][j] = -1;
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            a = parent[a][i];
        }
    }
    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

ll query_path(int a, int b) {
    int p = lca(a, b);
    return dist[a] + dist[b] - 2 * dist[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ll w = 1;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    preprocess(n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query_path(a, b) << '\n';
    }

    return 0;
}