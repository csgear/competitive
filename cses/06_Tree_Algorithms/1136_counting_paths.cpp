// https://cses.fi/problemset/task/1136

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];
int diff[MAXN], ans[MAXN];
int n, m;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        } else {
            up[u][i] = -1;
        }
    }

    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff_depth = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff_depth >> i) & 1) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void solve(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            solve(v, u);
            diff[u] += diff[v];
        }
    }
    ans[u] = diff[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        diff[a]++;
        diff[b]++;
        diff[l]--;
        if (up[l][0] != -1) {
            diff[up[l][0]]--;
        }
    }

    solve(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}
