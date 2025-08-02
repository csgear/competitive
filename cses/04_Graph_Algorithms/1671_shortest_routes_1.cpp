// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, nxt;
    ll w;
} edges[MAXN << 2];

int head[MAXN], cnt = 1;
int n, m;

void addEdge(int u, int v, ll weight) {
    edges[cnt] = {v, head[u], weight};
    head[u] = cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        ll weight;
        cin >> u >> v >> weight;
        addEdge(u, v, weight);
    }

    vector<ll> dist(n + 1, LLONG_MAX);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }

        for (int e = head[u]; e != 0; e = edges[e].nxt) {
            int v = edges[e].to;
            ll weight = edges[e].w;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}