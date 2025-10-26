// https://www.acwing.com/problem/content/1128/
// Maximum product path - alternative implementation
// Uses adjacency list instead of matrix
// Same approach: log transformation + shortest path

#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
const int M = 2e5 + 10;

struct Edge {
    int to, nxt;
    double w;
} edges[M];

int head[N], cnt;
double dist[N];
bool visited[N];
int n, m, s, t;

void add_edge(int u, int v, double w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

void dijkstra() {
    dist[s] = 1.0;
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, s});

    while (!pq.empty()) {
        auto [prob, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == t) break;

        for (int i = head[u]; i != 0; i = edges[i].nxt) {
            int v = edges[i].to;
            double w = edges[i].w;
            if (dist[u] * w > dist[v]) {
                dist[v] = dist[u] * w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    cnt = 1;
    for (int i = 1; i <= n; i++) head[i] = 0;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        double prob = (100.0 - c) / 100.0;
        add_edge(a, b, prob);
        add_edge(b, a, prob);
    }

    cin >> s >> t;

    dijkstra();

    cout << fixed << setprecision(8) << 100.0 / dist[t] << endl;

    return 0;
}