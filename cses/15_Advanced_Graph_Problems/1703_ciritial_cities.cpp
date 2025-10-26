// https://cses.fi/problemset/task/1703

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 4e5 + 10;  // 足够大
const int INF = 1e9;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N * 2], cnt = -1;
int d[N * 2], cur[N * 2];
int n, m, S, T;

void add_edge(int u, int v, int cap) {
    edges[++cnt] = {v, head[u], cap};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0};
    head[v] = cnt;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    d[S] = 0;
    cur[S] = head[S];
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edges[i].nxt) {
            int v = edges[i].to;
            if (d[v] == -1 && edges[i].cap > 0) {
                d[v] = d[u] + 1;
                cur[v] = head[v];
                if (v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dfs(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = edges[i].nxt) {
        cur[u] = i;
        int v = edges[i].to;
        if (d[v] == d[u] + 1 && edges[i].cap > 0) {
            int t = dfs(v, min(limit - flow, edges[i].cap));
            if (t == 0) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}

int dinic() {
    int maxFlow = 0;
    while (bfs()) {
        int flow;
        while ((flow = dfs(S, INF)) > 0) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(head, -1, sizeof head);
    cnt = -1;

    for (int i = 1; i <= n; i++) {
        add_edge(2 * i, 2 * i + 1, 1);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(2 * u + 1, 2 * v, INF);
        add_edge(2 * v + 1, 2 * u, INF);
    }

    S = 0;
    T = 2 * n + 2;

    add_edge(S, 2 * 1, INF);
    add_edge(2 * n + 1, T, INF);

    int maxFlow = dinic();

    return 0;
}