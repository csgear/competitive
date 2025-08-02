// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;

class UnionFind {
   public:
    int parent[MAXN];
    int size[MAXN];
    int components;
    int maxComponentSize;

    UnionFind(int n) {
        components = n;
        maxComponentSize = 1;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        if (size[u] < size[v]) swap(u, v);

        parent[v] = u;
        size[u] += size[v];
        components--;
        maxComponentSize = max(maxComponentSize, size[u]);
        return true;
    }

    int getComponents() { return components; }
    int getMaxSize() { return maxComponentSize; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        uf.merge(u, v);

        cout << uf.getComponents() << " " << uf.getMaxSize() << "\n";
    }

    return 0;
}