// https://atcoder.jp/contests/abc428/tasks/abc428_e

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int best_node = start;
    int best_dist = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > best_dist || (dist[i] == best_dist && i > best_node)) {
            best_dist = dist[i];
            best_node = i;
        }
    }

    return {best_node, dist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // compute diameter (A, B)
    auto [A, dist1] = bfs(1, graph);
    auto [B, distA] = bfs(A, graph);

    auto [dummy, distB] = bfs(B, graph);

    for (int v = 1; v <= n; ++v) {
        int d1 = distA[v];
        int d2 = distB[v];

        if (d1 > d2) {
            cout << A << '\n';
        } else if (d2 > d1) {
            cout << B << '\n';
        } else {
            cout << max(A, B) << '\n';
        }
    }

    return 0;
}