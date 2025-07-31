// https://cses.fi/problemset/task/1696

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> match;
vector<bool> used;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (used[v]) continue;
        used[v] = true;

        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    adj.resize(n + 1);
    match.assign(m + 1, -1);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int result = 0;
    for (int u = 1; u <= n; u++) {
        used.assign(m + 1, false);
        if (dfs(u)) {
            result++;
        }
    }

    cout << result << '\n';

    for (int v = 1; v <= m; v++) {
        if (match[v] != -1) {
            cout << match[v] << " " << v << '\n';
        }
    }

    return 0;
}