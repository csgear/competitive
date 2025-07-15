// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> team;
bool is_bipartite = true;

void dfs(int u, int c) {
    team[u] = c;
    for (int v : adj[u]) {
        if (team[v] == -1) {
            dfs(v, 1 - c);
        } else if (team[v] == c) {
            is_bipartite = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    team.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            dfs(i, 0);
        }
    }

    if (is_bipartite) {
        for (int i = 1; i <= n; i++) {
            cout << team[i] + 1 << " ";
        }
        cout << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
