// https://atcoder.jp/contests/abc408/tasks/abc408_e

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> g[200005];
bool vis[200005];

bool dfs(int u, int mx) {
    if (u == n) return true;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
        if (vis[v]) continue;
        if ((mx | w) != mx) continue;
        if (dfs(v, mx)) return true;
    }
    return false;
}

bool check(int mx) {
    memset(vis, 0, sizeof(vis));
    return dfs(1, mx);
}

void solve() {
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        if (!check(ans + (1 << i) - 1)) {
            ans += (1 << i);
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    solve();
    return 0;
}
