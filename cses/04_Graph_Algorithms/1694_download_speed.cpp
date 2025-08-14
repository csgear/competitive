// https://cses.fi/problemset/task/1694

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const int N = 505;

struct edge {
    int v, nxt, cap, flow;
} e[N << 2];

int head[N], cnt = 0;
int n, m, S, T;
ll maxflow = 0;
int dep[N], cur[N];

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
    maxflow = 0;
}

void addedge(int u, int v, int w) {
    e[cnt] = {v, head[u], w, 0};
    head[u] = cnt++;
    e[cnt] = {u, head[v], 0, 0};
    head[v] = cnt++;
}

bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (n + 1));

    dep[S] = 1;
    q.push(S);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].v;
            if ((!dep[v]) && (e[i].cap > e[i].flow)) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[T];
}

ll dfs(int u, ll flow) {
    if ((u == T) || (!flow)) return flow;

    ll ret = 0;
    for (int& i = cur[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        ll d;
        if ((dep[v] == dep[u] + 1) && (d = dfs(v, min(flow - ret, (ll)(e[i].cap - e[i].flow))))) {
            ret += d;
            e[i].flow += d;
            e[i ^ 1].flow -= d;
            if (ret == flow) return ret;
        }
    }
    return ret;
}

void dinic() {
    while (bfs()) {
        memcpy(cur, head, sizeof(int) * (n + 1));
        maxflow += dfs(S, INF);
    }
}

int main() {
    cin >> n >> m;

    init();
    S = 1;
    T = n;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    dinic();
    cout << maxflow << endl;
}