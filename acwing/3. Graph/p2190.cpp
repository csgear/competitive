// https://www.acwing.com/problem/content/2192/
// Minimum flow with source and sink, lower/upper bounds
// Find feasible flow, add t→s edge, then push back flow from t to s
// Answer = initial flow through t→s minus pushback amount

#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
const int M = (125003 + N) * 2;
const int INF = 2147483647;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N], A[N];
int n, m, s, t, S, T;

void add_edge(int u, int v, int c) {
    edges[++cnt] = {v, head[u], c};
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
    int max_flow = 0;
    while (bfs()) {
        int flow;
        while ((flow = dfs(S, INF)) > 0) {
            max_flow += flow;
        }
    }
    return max_flow;
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add_edge(a, b, d - c);
        A[a] -= c;
        A[b] += c;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            tot += A[i];
            add_edge(S, i, A[i]);
        } else if (A[i] < 0) {
            add_edge(i, T, -A[i]);
        }
    }

    add_edge(t, s, INF);

    if (dinic() < tot) {
        cout << "No Solution" << endl;
        return 0;
    }

    int res = edges[cnt].cap;
    edges[cnt].cap = 0;
    edges[cnt ^ 1].cap = 0;
    S = t;
    T = s;

    cout << res - dinic() << endl;

    return 0;
}
