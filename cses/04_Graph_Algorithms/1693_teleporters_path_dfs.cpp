// https://cses.fi/problemset/task/1693

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int to, next;
    bool used;
} edges[MAXM];

int head[MAXN], cnt = 1;
int in_degree[MAXN], out_degree[MAXN];
int cur[MAXN];
vector<int> path;

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u], false};
    head[u] = cnt++;
    out_degree[u]++;
    in_degree[v]++;
}

void dfs(int u) {
    // Find next unused edge
    while (cur[u] != 0 && edges[cur[u]].used) {
        cur[u] = edges[cur[u]].next;
    }

    while (cur[u] != 0) {
        int edge_id = cur[u];
        int v = edges[edge_id].to;
        edges[edge_id].used = true;
        cur[u] = edges[edge_id].next;
        dfs(v);
    }

    // Add current node to path when backtracking
    path.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        cur[i] = head[i];
    }

    // Check Eulerian path conditions
    if (out_degree[1] != in_degree[1] + 1 || in_degree[n] != out_degree[n] + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (in_degree[i] != out_degree[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Find Eulerian path using DFS-based Hierholzer's algorithm
    dfs(1);

    // Check if we used all edges and ended at n
    if (path.size() != m + 1 || path.back() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Output path in reverse order (since DFS builds it backwards)
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " ";
    }
    cout << "\n";

    return 0;
}
