// https://cses.fi/problemset/task/1673


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, long long>>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        graph[a].push_back({b, x});
    }
    
    // Bellman-Ford for LONGEST path
    vector<long long> dist(n + 1, LLONG_MIN);
    dist[1] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist[u] == LLONG_MIN) continue;
            for (auto [v, w] : graph[u]) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    
    vector<bool> has_pos_cycle(n + 1, false);
    for (int u = 1; u <= n; u++) {
        if (dist[u] == LLONG_MIN) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                has_pos_cycle[v] = true;
            }
        }
    }
    
    // Propagate positive cycle flag to all reachable nodes
    for (int i = 0; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (has_pos_cycle[u]) {
                for (auto [v, w] : graph[u]) {
                    has_pos_cycle[v] = true;
                }
            }
        }
    }
    
    if (has_pos_cycle[n]) {
        cout << -1 << "\n";  // Node n affected by positive cycle
    } else {
        cout << dist[n] << "\n";
    }
    
    return 0;
}