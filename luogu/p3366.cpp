// https://www.luogu.com.cn/problem/P3366

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000 + 5;
int parent[MAXN];
int n, m;

const int MAXM = 200005 * 2;  // 2*m

struct Edge {
    int to, w, next;
} edges[MAXM];
int head[MAXN], tot = 0;

bool vis[MAXN];

void add(int u, int v, int w) {
    edges[++tot] = {v, w, head[u]};
    head[u] = tot;
}

void prim_linked_star() {
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vis[1] = true;
    for (int i = head[1]; i; i = edges[i].next) {
        pq.push({edges[i].w, edges[i].to});
    }
    int ans = 0, edge = 0;
    while (!pq.empty() && edge < n - 1) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans += w;
        edge++;
        for (int i = head[u]; i; i = edges[i].next) {
            if (!vis[edges[i].to]) {
                pq.push({edges[i].w, edges[i].to});
            }
        }
    }
    if (edge == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
}

void prim() {
    // 考虑每个顶点，向外扩展，选择最小的边
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<bool> vis(n + 1, false);
    vis[1] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &[v, w] : g[1]) {
        pq.push({w, v});
    }

    int ans = 0;
    int edge = 0;
    while (!pq.empty() && edge < n - 1) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        ans += w;
        edge++;
        vis[u] = true;
        for (auto &[v, w] : g[u]) {
            if (vis[v]) continue;
            pq.push({w, v});
        }
    }
    if (edge == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    parent[u] = v;
}

void kruskal() {
    // 考虑每条边，做并查集合并顶点
    vector<tuple<int, int, int>> g(m);

    for (auto &[w, u, v] : g) {
        cin >> u >> v >> w;
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    sort(g.begin(), g.end());

    int ans = 0;
    int edge = 0;
    for (auto &[w, u, v] : g) {
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
        edge++;
    }
    if (edge == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
}

int main() {
    cin >> n >> m;

    prim_linked_star();
    return 0;
}