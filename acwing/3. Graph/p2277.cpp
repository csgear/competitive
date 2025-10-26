// https://www.acwing.com/problem/content/2279/

#include <bits/stdc++.h>
using namespace std;

const int N = 210, M = 80010;

struct Edge {
    int to, nxt, w, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];

int n, m, K, S, T;

void add(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], w};
    head[v] = cnt;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    d[S] = 0;
    cur[S] = head[S];
    q.push(S);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (d[v] == -1 && edges[i].cap > 0) {
                d[v] = d[u] + 1;
                if (v == T) return true;
                cur[v] = head[v];
                q.push(v);
            }
        }
    }
    return false;
}

int dfs(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; i != -1 && flow < limit; i = edges[i].nxt) {
        cur[u] = i;
        int v = edges[i].to;
        if (d[v] == d[u] + 1 && edges[i].cap > 0) {
            int t = dfs(v, min(limit - flow, edges[i].cap));
            if (!t) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        flow += dfs(S, INT_MAX);
    }
    return flow;
}

bool check(int mid) {
    for (int i = 0; i <= cnt; i++) {
        if (edges[i].w > mid)
            edges[i].cap = 0;
        else
            edges[i].cap = 1;
    }
    return dinic() >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> K;
    S = 1, T = n;

    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    int l = 1, r = 1e6;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}