// https://www.acwing.com/problem/content/2238/
// Minimum cut - find cut edges in max flow
// Run max flow, then DFS from source in residual graph
// Cut edges: forward edges from S-side to T-side with capacity 0

#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int M = 10010;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];
bool in_S[N], in_T[N];

int n, m, S, T;

void add(int u, int v, int cap) {
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
    int max_flow = 0;
    while (bfs()) {
        int flow = dfs(S, 1e9);
        if (!flow) break;
        max_flow += flow;
    }
    return max_flow;
}

void dfs(int u, bool visited[], int sign) {
    visited[u] = true;
    for (int i = head[u]; i != -1; i = edges[i].nxt) {
        int v = edges[i].to;
        if (!visited[v] && edges[i ^ sign].cap > 0) {
            dfs(v, visited, sign);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    S = 0, T = n - 1;

    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int a, b, cap;
        cin >> a >> b >> cap;
        add(a, b, cap);
    }

    dinic();

    dfs(S, in_S, 0);
    dfs(T, in_T, 1);

    int ans = 0;
    for (int i = 0; i <= cnt; i += 2) {
        int u = edges[i ^ 1].to;
        int v = edges[i].to;
        if (in_S[u] && in_T[v] && edges[i].cap == 0) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}