// https://www.acwing.com/problem/content/2177/
// max bipartite matching - Dinic's algorithm

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 10010;

struct Edge {
    int to, nxt, c;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];

int n, m, S, T;

void add_edge(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S);
    d[S] = 0;
    cur[S] = head[S];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (d[v] == -1 && edges[i].c > 0) {
                d[v] = d[u] + 1;
                cur[v] = head[v];
                q.push(v);
                if (v == T) return true;
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
        if (d[v] == d[u] + 1 && edges[i].c > 0) {
            int t = dfs(v, min(limit - flow, edges[i].c));
            if (!t) d[v] = -1;
            edges[i].c -= t;
            edges[i ^ 1].c += t;
            flow += t;
        }
    }
    return flow;
}

int dinic() {
    int max_flow = 0;
    while (bfs()) {
        max_flow += dfs(S, INT_MAX);
    }
    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> m >> n;
    S = 0;
    T = n + 1;

    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        add_edge(u, v, 1);
        add_edge(v, u, 0);
    }

    for (int i = 1; i <= m; i++) {
        add_edge(0, i, 1);
        add_edge(i, 0, 0);
    }

    for (int i = m + 1; i <= n; i++) {
        add_edge(i, T, 1);
        add_edge(T, i, 0);
    }

    cout << dinic() << endl;

    for (int i = 0; i <= cnt; i = i + 2) {
        int to = edges[i].to;
        if (to > m && to <= n && edges[i].c == 0) {
            cout << edges[i ^ 1].to << " " << edges[i].to << endl;
        }
    }

    return 0;
}