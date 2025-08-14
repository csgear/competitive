// https://cses.fi/problemset/task/1693

// Eulerian Trail (but not circuit): Exactly two
// vertices have odd degree (start and end vertices), and the graph is connected.

#include <bits/stdc++.h>
using namespace std;

vector<int> hierholzer(vector<vector<int>>& adj, int start) {
    stack<int> stk;
    vector<int> circuit;

    stk.push(start);

    while (!stk.empty()) {
        int u = stk.top();
        if (!adj[u].empty()) {
            // Get the last neighbor
            int v = adj[u].back();
            // remove the edge
            adj[u].pop_back();
            stk.push(v);
        } else {
            circuit.push_back(stk.top());
            stk.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0), out_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
    }

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

    vector<int> path = hierholzer(adj, 1);

    if (path.size() != m + 1 || path[0] != 1 || path.back() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i == path.size() - 1];
    }

    return 0;
}