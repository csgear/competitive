// https://www.acwing.com/problem/content/2182/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int M = 251010;
const int INF = 1e8;

struct Edge {
    int to, next, cap;
} edges[M];
int head[N], cnt = -1;
int d[N], cur[N];
int f[N], a[N];
int n, S, T;

void add(int u, int v, int cap) {
    edges[++cnt] = {v, head[u], cap};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0};
    head[v] = cnt;
}

int dp() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }
    return res;
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
        for (int i = head[u]; i != -1; i = edges[i].next) {
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
    for (int i = cur[u]; i != -1 && flow < limit; i = edges[i].next) {
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = dp();
    cout << m << endl;

    memset(head, -1, sizeof head);

    S = 0;
    T = 2 * n + 2;

    for (int i = 1; i <= n; i++) {
        add(i, i + n, 1);
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] == 1) {
            add(S, i, 1);
        }
        if (f[i] == m) {
            add(i + n, T, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] >= a[i] && f[j] == f[i] + 1) {
                add(i + n, j, 1);
            }
        }
    }

    int res = dinic();
    cout << res << endl;

    for (int i = 0; i <= cnt; i++) {
        int a = edges[i ^ 1].to;
        int b = edges[i].to;

        if (a == S && b == 1) edges[i].cap = INF;
        if (a == 1 && b == 1 + n) edges[i].cap = INF;
        if (a == n && b == n + n) edges[i].cap = INF;
        if (a == n + n && b == T) edges[i].cap = INF;
    }

    res += dinic();
    cout << res << endl;

    return 0;
}