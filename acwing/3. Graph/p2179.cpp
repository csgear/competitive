// https://www.acwing.com/problem/content/2181/
// Multiple bipartite matching with capacity constraints
// Each left/right node has capacity limit, model as max flow
// Uses Dinic's algorithm with capacitated nodes

#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int M = 100000;

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
    int res = 0, flow;
    while (bfs())
        while (flow = dfs(S, INF)) res += flow;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> m >> n;

    S = 0;
    T = n + m + 1;

    int total_r = 0;
    for (int i = 1; i <= m; i++) {
        int r;
        cin >> r;
        add_edge(0, i, r);
        add_edge(i, 0, 0);
        total_r += r;
    }

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        add_edge(i + m, T, c);
        add_edge(T, i + m, 0);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            add_edge(i, j + m, 1);
            add_edge(j + m, i, 0);
        }
    }

    int ans = dinic();

    if (ans != total_r) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
        for (int i = 1; i <= m; i++) {
            for (int j = head[i]; j != -1; j = edges[j].nxt) {
                int to = edges[j].to;
                if (to > m && to <= m + n && edges[j].c == 0) {
                    cout << to - m << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}