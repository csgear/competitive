// https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2505;
const int MAXM = 5005;

struct Edge {
    int to, nxt;
    int c;
} edges[MAXM];

int head[MAXN], cnt = 1;

void addEdge(int u, int v, int c) {
    edges[cnt] = {v, head[u], c};
    head[u] = cnt++;
}

bool hasNegativeCycle(int n) {
    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    // Bellman-Ford algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (int e = head[u]; e != 0; e = edges[e].nxt) {
                int v = edges[e].to;
                int c = edges[e].c;
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles and find a node in the cycle
    int cycle_node = -1;
    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e != 0; e = edges[e].nxt) {
            int v = edges[e].to;
            int c = edges[e].c;
            if (dist[v] > dist[u] + c) {
                cycle_node = v;
                parent[v] = u;
                break;
            }
        }
        if (cycle_node != -1) break;
    }

    if (cycle_node == -1) {
        cout << "NO\n";
        return false;
    }

    // Find a node that is definitely in the negative cycle
    // Move n steps back from cycle_node to ensure we're in the cycle
    for (int i = 0; i < n; i++) {
        cycle_node = parent[cycle_node];
    }

    // Reconstruct the cycle
    vector<int> cycle;
    int current = cycle_node;
    do {
        cycle.push_back(current);
        current = parent[current];
    } while (current != cycle_node);

    cycle.push_back(cycle_node);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << "\n";

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        addEdge(u, v, c);
    }

    hasNegativeCycle(n);

    return 0;
}