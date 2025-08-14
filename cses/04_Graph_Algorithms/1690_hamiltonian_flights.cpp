// https://cses.fi/problemset/task/1690

// Hamiltonian Path: A path in a graph that visits each vertex exactly once.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int countHamiltonianPaths(vector<vector<int>>& graph, int n) {
    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
    dp[1][0] = 1;
    for (int mask = 1; mask <= (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == 0) continue;

            for (int v = 0; v < n; v++) {
                if (u == v) continue;
                if (mask & (1 << v)) continue;
                if (graph[u][v] > 0) {
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = (dp[newMask][v] + dp[mask][u] * graph[u][v]) % MOD;
                }
            }
        }
    }
    return dp[(1 << n) - 1][n - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u][v]++;  // Count multiple edges
    }
    cout << countHamiltonianPaths(graph, n) << endl;
    return 0;
}