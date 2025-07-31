// https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100005;

struct Edge {
    int to, nxt;
    ll w;
} edges[MAXN << 2];

int head[MAXN], cnt = 1;

void addEdge(int u, int v, long long w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

ll dist[MAXN][2];

void dijkstra(int n) {
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>>
        pq;

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = LLONG_MAX;
    }

    dist[1][0] = 0;
    pq.push({0, 1, 0});  // {distance, node, used_discount}

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d > dist[u][used]) continue;

        for (int e = head[u]; e != 0; e = edges[e].nxt) {
            int v = edges[e].to;
            ll w = edges[e].w;

            // Option 1: Use edge without discount
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }

            // Option 2: Use edge with discount (if not used before)
            if (used == 0) {
                ll new_dist = dist[u][0] + w / 2;
                if (dist[v][1] > new_dist) {
                    dist[v][1] = new_dist;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        addEdge(u, v, w);  // Only add directed edge u -> v
    }

    dijkstra(n);

    cout << min(dist[n][0], dist[n][1]) << '\n';

    return 0;
}