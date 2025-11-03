// https://www.acwing.com/problem/content/1075/
// 1073. 树的中心

#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 2 * N, INF = 0x3f3f3f3f;

struct Edge {
    int to, next, w;
} edge[M];

int head[N], cnt = -1;
int n;
int d1[N], d2[N], son1[N], up[N];

int dfs_down(int u, int fa) {
    d1[u] = d2[u] = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to, w = edge[i].w;
        if (v == fa) continue;
        int dist = dfs_down(v, u) + w;
        if (dist > d1[u]) {
            d2[u] = d1[u];
            d1[u] = dist, son1[u] = v;
        } else if (dist > d2[u]) {
            d2[u] = dist;
        }
    }
    return d1[u];
}

void dfs_up(int u, int fa) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to, w = edge[i].w;
        if (v == fa) continue;
        if (son1[u] == v) {
            up[v] = max(up[u], d2[u]) + w;
        } else {
            up[v] = max(up[u], d1[u]) + w;
        }
        dfs_up(v, u);
    }
}

void add_edge(int u, int v, int w) {
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dfs_down(1, -1);
    dfs_up(1, -1);

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(d1[i], up[i]));
    }
    cout << ans << endl;
    return 0;
}