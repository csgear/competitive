// https://cses.fi/problemset/task/2080

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
vector<int> adj[N];
int sz[N];
bool vis[N];
int cnt[N];
ll ans = 0;
int k, max_depth;

int get_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            sz[u] += get_size(v, u);
        }
    }
    return sz[u];
}

int find_centroid(int u, int p, int tree_size) {
    for (int v : adj[u]) {
        if (v != p && !vis[v] && sz[v] > tree_size / 2) {
            return find_centroid(v, u, tree_size);
        }
    }
    return u;
}

void dfs(int u, int p, int depth, bool add) {
    if (depth > k) return;
    max_depth = max(max_depth, depth);

    if (add) {
        cnt[depth]++;
    } else {
        ans += cnt[k - depth];
    }

    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            dfs(v, u, depth + 1, add);
        }
    }
}

void solve(int u) {
    int tree_size = get_size(u, -1);
    int centroid = find_centroid(u, -1, tree_size);
    vis[centroid] = true;

    max_depth = 0;
    cnt[0] = 1;

    for (int v : adj[centroid]) {
        if (!vis[v]) {
            dfs(v, centroid, 1, false);  // Count paths
            dfs(v, centroid, 1, true);   // Add to counter
        }
    }

    // Clear counter
    for (int i = 0; i <= max_depth; i++) {
        cnt[i] = 0;
    }

    // Recurse on subtrees
    for (int v : adj[centroid]) {
        if (!vis[v]) {
            solve(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1);

    cout << ans << "\n";
    return 0;
}