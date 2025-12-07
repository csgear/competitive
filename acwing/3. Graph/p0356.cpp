// https://www.acwing.com/problem/content/description/358/
// 356. 次小生成树

#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 300010;

struct Edge {
    int to, next, w;
} edges[M];

int head[N], idx = -1;
int dist[N];

void add_edge(int u, int v, int w) {
    edges[++idx] = {v, head[u], w};
    head[u] = idx;
}

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    return 0;
}