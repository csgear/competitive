// https://www.acwing.com/problem/content/2174/
// Maximum flow - Dinic's algorithm with level graph and blocking flow
// BFS builds level graph, DFS finds blocking flow with current arc optimization
// Time: O(V²E), better for dense graphs, O(E√V) for unit capacity

#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
const int M = 200010;

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

    cin >> n >> m >> S >> T;

    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }

    cout << dinic() << endl;

    return 0;
}
