// https://www.acwing.com/problem/content/2191/
// Maximum flow with source and sink, lower/upper bounds on edges
// Add auxiliary edge t→s, find circulation, then compute s→t max flow
// Uses Dinic's algorithm with lower bound transformation

#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int M = (10200 + N) * 2;
const int INF = 2147483647;

int head[N], cnt = -1;
int d[N], cur[N], A[N];

int n, m, s, t, S, T;

struct Edge {
    int to, nxt, cap;
} edges[M];

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
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
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
    int res = 0, flow;
    while (bfs())
        while (flow = dfs(S, INF)) res += flow;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m >> s >> t;

    S = 0;
    T = n + 1;
    int tot = 0;
    for (int i = 0; i < m; i++) {
        int u, v, low, upper;
        cin >> u >> v >> low >> upper;
        add_edge(u, v, upper - low);
        A[u] -= low;
        A[v] += low;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            add_edge(S, i, A[i]);
            tot += A[i];
        } else if (A[i] < 0) {
            add_edge(i, T, -A[i]);
        }
    }

    add_edge(t, s, INF);

    if (dinic() < tot) {
        cout << "No Solution" << "\n";
    } else {
        int res = edges[cnt].cap;
        S = s;
        T = t;
        edges[cnt].cap = 0;
        edges[cnt ^ 1].cap = 0;
        cout << dinic() + res << "\n";
    }

    return 0;
}