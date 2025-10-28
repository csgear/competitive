// https://www.acwing.com/problem/content/2176/
// mcmf - min cost max flow using SPFA
// Finds max flow with minimum cost in a flow network

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5010;
const int M = 50010;
const ll INF = 1e18;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M * 2];

int head[N], cnt = -1;
ll dist[N];
int pre[N];
bool inq[N];

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa(int S, int T, int n) {
    fill(dist, dist + n + 1, INF);
    fill(inq, inq + n + 1, false);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    inq[S] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (edges[i].cap > 0 && dist[v] > dist[u] + edges[i].cost) {
                dist[v] = dist[u] + edges[i].cost;
                pre[v] = i;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return dist[T] != INF;
}

pair<ll, ll> mcmf(int S, int T, int n) {
    ll max_flow = 0, min_cost = 0;
    while (spfa(S, T, n)) {
        ll flow = INF;
        for (int i = T; i != S; i = edges[pre[i] ^ 1].to) {
            flow = min(flow, edges[pre[i]].cap);
        }
        for (int i = T; i != S; i = edges[pre[i] ^ 1].to) {
            edges[pre[i]].cap -= flow;
            edges[pre[i] ^ 1].cap += flow;
        }
        max_flow += flow;
        //  the flow increment on every edge along the path is exactly flow
        min_cost += flow * dist[T];
    }
    return {max_flow, min_cost};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    int n, m, S, T;
    cin >> n >> m >> S >> T;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w, c;
        cin >> u >> v >> w >> c;
        add_edge(u, v, w, c);
    }

    auto [flow, cost] = mcmf(S, T, n);
    cout << flow << " " << cost << '\n';

    return 0;
}
