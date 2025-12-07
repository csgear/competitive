// https://www.acwing.com/problem/content/1173/
// 1171. 距离

#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = 2 * N, Q = 20010;

struct Edge {
    int to, next, w;
} edges[M];

int head[N], idx = -1;
int dist[N], p[N], ans[Q];
int st[N];                          // 0: unvisited, 1: visiting, 2: visited
vector<pair<int, int>> queries[N];  // queries[u] = {(v, query_id)}
int n, m;

void add_edge(int u, int v, int w) {
    edges[++idx] = {v, head[u], w};
    head[u] = idx;
}

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void tarjan(int u) {
    st[u] = 1;  // visiting

    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (st[v]) continue;
        dist[v] = dist[u] + edges[i].w;
        tarjan(v);
        p[v] = u;
    }

    st[u] = 2;  // visited

    for (auto [v, qid] : queries[u]) {
        if (st[v] == 2) {
            int lca = find(v);
            ans[qid] = dist[u] + dist[v] - 2 * dist[lca];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m;

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v) {
            // else dist = 0
            queries[u].push_back({v, i});
            queries[v].push_back({u, i});
        }
    }

    // Initialize union-find
    for (int i = 1; i <= n; i++) p[i] = i;

    // Root = 1, dist[1] = 0
    dist[1] = 0;
    tarjan(1);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}