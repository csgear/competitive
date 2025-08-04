// https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
    int u, v;
    long long cost;
    bool operator<(const Edge& other) const { return cost < other.cost; }
};

int parent[MAXN];
int components;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    parent[u] = v;
    components--;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    components = n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long totalCost = 0;
    int edgesUsed = 0;

    // Kruskal's algorithm
    for (const auto& edge : edges) {
        if (merge(edge.u, edge.v)) {
            totalCost += edge.cost;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    if (components == 1) {
        cout << totalCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}