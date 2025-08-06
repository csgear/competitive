// https://cses.fi/problemset/task/1678

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int to, nxt;
} edges[MAXN << 1];

int head[MAXN], cnt = 1;
int color[MAXN];  // 0: white, 1: gray, 2: black
int parent[MAXN];
vector<int> cycle;

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

bool dfs(int u) {
    color[u] = 1;

    for (int i = head[u]; i; i = edges[i].nxt) {
        int v = edges[i].to;

        if (color[v] == 1) {
            cycle.push_back(v);
            for (int cur = u; cur != v; cur = parent[cur]) {
                cycle.push_back(cur);
            }
            cycle.push_back(v);
            return true;
        }

        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
    }
    color[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                cout << cycle.size() << '\n';
                for (int j = cycle.size() - 1; j >= 0; j--) {
                    cout << cycle[j] << " ";
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}