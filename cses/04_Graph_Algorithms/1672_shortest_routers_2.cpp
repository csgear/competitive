// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 505;
ll dist[MAXN][MAXN];

struct Edge {
    int to, nxt;
    ll w;
} edges[MAXN * MAXN * 2];

int head[MAXN], cnt = 1;

void addEdge(int u, int v, ll w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

void floyd(int n) {
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = LLONG_MAX;
        }
        dist[i][i] = 0;
    }

    // Add edge weights from adjacency list
    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e != 0; e = edges[e].nxt) {
            int v = edges[e].to;
            ll w = edges[e].w;
            dist[u][v] = min(dist[u][v], w);  // Handle multiple edges
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    floyd(n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == LLONG_MAX) {
            cout << -1 << '\n';
        } else {
            cout << dist[a][b] << '\n';
        }
    }

    return 0;
}
