// https://www.acwing.com/problem/content/2282/
// Binary search on number of free edges + max flow (Dinic's)
// For each k, build graph with k free edges, compute max flow
// Find minimum k where max flow ≥ target threshold

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510, M = (3000 + N) * 2 + 10, INF = 1e8;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];
int n, m, K, S, T;
int p[N];
pii g[3010];

void add_edge(int u, int v, int cap, int rev = 0) {
    edges[++cnt] = {v, head[u], cap};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], rev};
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
            if (t == 0) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}

ll dinic() {
    ll res = 0, flow;
    while (bfs())
        while (flow = dfs(S, INF)) res += flow;
    return res;
}

ll solve(int k) {
    memset(head, -1, sizeof head);
    cnt = -1;
    for (int i = 1; i <= m; i++) {
        int u = g[i].first, v = g[i].second;
        add_edge(u, v, 1, 1);
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] != -1) {
            if (p[i] >> k & 1) {
                add_edge(i, T, INF, 0);
            } else {
                add_edge(S, i, INF, 0);
            }
        }
    }
    ll ans = dinic();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    S = 0, T = n + 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[i] = {u, v};
    }

    memset(p, -1, sizeof p);
    cin >> K;
    for (int i = 1; i <= K; i++) {
        int a, b;
        cin >> a >> b;
        p[a] = b;
    }

    ll ans = 0;

    for (int i = 0; i <= 30; i++) ans += solve(i) << i;
    cout << ans << '\n';
    return 0;
}
