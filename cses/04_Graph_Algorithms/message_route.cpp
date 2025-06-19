// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parents;

bool bfs(int src, int target) {
    visited.assign(n + 1, false);

    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                parents[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[target];
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    parents.resize(n + 1, -1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (!bfs(1, n)) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // output the path
        vector<int> path;
        int cur = n;
        while (cur != 1) {
            path.push_back(cur);
            cur = parents[cur];
        }
        path.push_back(1);
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}