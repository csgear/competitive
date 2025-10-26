// https://www.acwing.com/problem/content/2190/
// Feasible flow - max flow with lower and upper bounds on edges
// Transform to standard max flow: add super source/sink for balance
// Stores both lower bound and capacity (upper - lower)

#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int M = (10200 + N) * 2;

struct Edge {
    int to, nxt, low, cap;
} edges[M];

int head[N], cnt = -1;

int d[N], cur[N], A[N];

int n, m, S, T;

void add_edge(int u, int v, int low, int upper) {
    edges[++cnt] = {v, head[u], low, upper - low};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, 0};
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
        max_flow += dfs(S, INT_MAX);
    }
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m;
    S = 0, T = n + 1;

    for (int i = 1; i <= n; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, low, upper;
        cin >> u >> v >> low >> upper;
        add_edge(u, v, low, upper);
        A[u] -= low;
        A[v] += low;
    }

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            add_edge(S, i, 0, A[i]);
            tot += A[i];
        } else if (A[i] < 0) {
            add_edge(i, T, 0, -A[i]);
        }
    }

    int flow = dinic();

    if (flow != tot) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m * 2; i += 2) {
            cout << edges[i ^ 1].cap + edges[i].low << "\n";
        }
    }

    return 0;
}
