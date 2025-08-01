// https://cses.fi/problemset/task/1196

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, nxt;
    ll price;
} edges[MAXN << 2];

int head[MAXN], cnt = 1;

void add_edge(int u, int v, ll price) {
    edges[cnt] = {v, head[u], price};
    head[u] = cnt++;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll price;
        cin >> u >> v >> price;
        add_edge(u, v, price);
    }

    reverse_priority_queue<pair<ll, int>> pq;
    vector<vector<ll>> dist(n + 1);

    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= k) continue;

        dist[u].push_back(d);

        if (u == n && dist[n].size() == k) break;

        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            ll w = edges[i].price;

            if (dist[v].size() < k) {
                pq.push({d + w, v});
            }
        }
    }

    for (ll cost : dist[n]) {
        cout << cost << " ";
    }
    cout << "\n";

    return 0;
}