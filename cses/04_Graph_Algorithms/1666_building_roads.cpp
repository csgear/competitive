// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (i > 1) {
                roads.push_back({i - 1, i});
            }
            dfs(i);
        }
    }

    cout << roads.size() << endl;
    for (auto [a, b] : roads) cout << a << " " << b << endl;
    return 0;
}