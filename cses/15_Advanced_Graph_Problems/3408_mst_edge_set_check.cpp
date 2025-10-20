// https://cses.fi/problemset/task/3408

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
int n, m, q;

int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[x] = y;
    return true;
}

void reset_dsu() {
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    edges.reserve(m + 1);
    for (int i = 1; i <= m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.cost;
        e.id = i;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end());

    vector<char> must_flag(m + 1);

    while (q--) {
        int sz;
        cin >> sz;

        fill(must_flag.begin(), must_flag.end(), 0);

        for (int i = 0; i < sz; ++i) {
            int id;
            cin >> id;
            if (id >= 1 && id <= m) must_flag[id] = 1;
        }

        reset_dsu();

        bool ok = true;
        int i = 0;
        while (i < m && ok) {
            int j = i;
            while (j < m && edges[j].cost == edges[i].cost) ++j;

            for (int k = i; k < j; ++k) {
                if (must_flag[edges[k].id]) {
                    if (!merge(edges[k].u, edges[k].v)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) break;

            for (int k = i; k < j; ++k) {
                if (!must_flag[edges[k].id]) {
                    merge(edges[k].u, edges[k].v);
                }
            }

            i = j;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
