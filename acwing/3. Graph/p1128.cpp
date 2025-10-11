// https://www.acwing.com/problem/content/1131/

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 410;
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

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    cnt = 1;

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

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

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, dist[i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
