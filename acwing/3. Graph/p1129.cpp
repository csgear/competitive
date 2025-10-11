// https://www.acwing.com/problem/content/1131/

#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
const int M = 13000;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt, dist[N];
bool st[N];

void add_edge(int u, int v, int w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

int t, c, ts, te;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> c >> ts >> te;

    cnt = 1;

    for (int i = 1; i <= c; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }

    memset(dist, 0x3f, sizeof dist);
    dist[ts] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, ts});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (st[u]) continue;
        st[u] = true;

        for (int k = head[u]; k != 0; k = edges[k].nxt) {
            int v = edges[k].to, w = edges[k].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[te] == INF)
        cout << -1 << endl;
    else
        cout << dist[te] << endl;
    return 0;
}
