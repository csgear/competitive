// https://cses.fi/problemset/task/3407

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

struct Edge {
    int id;
    int u, v;
    LL cost;
    bool operator<(const Edge& other) const { return cost < other.cost; }
};

vector<Edge> edges;
int parent[N];
int n, m;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
        return true;
    }
    return false;
}

void reset_dsu() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<bool> results(m, false);

    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.cost;
        e.id = i;
        edges.push_back(e);
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Initialize DSU only once
    reset_dsu();

    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && edges[j].cost == edges[i].cost) {
            j++;
        }

        for (int k = i; k < j; k++) {
            if (find(edges[k].u) != find(edges[k].v)) {
                results[edges[k].id] = true;
            }
        }

        for (int k = i; k < j; k++) {
            merge(edges[k].u, edges[k].v);
        }

        i = j;
    }

    // Output results in original order
    for (int i = 0; i < m; i++) {
        cout << (results[i] ? "YES" : "NO") << "\n";
    }

    return 0;
}