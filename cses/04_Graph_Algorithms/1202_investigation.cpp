// https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

struct Edge {
    int to, nxt;
    ll price;
} edges[MAXN << 1];

int head[MAXN], cnt = 1;

void add_edge(int u, int v, ll price) {
    edges[cnt] = {v, head[u], price};
    head[u] = cnt++;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll price;
        cin >> u >> v >> price;
        add_edge(u, v, price);
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> ways(n + 1, 0);
    vector<int> minFlights(n + 1, INT_MAX);
    vector<int> maxFlights(n + 1, 0);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            ll w = edges[i].price;
            ll newDist = dist[u] + w;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({newDist, v});
            } else if (newDist == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;

    return 0;
}