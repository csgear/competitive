// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 4e5 + 5;

int head[MAXN], to[MAXM], nxt[MAXM];
int parent[MAXN], visited[MAXN];

int cnt = 0;
int start_node, end_node;

bool dfs(int u, int p) {
    visited[u] = 1;
    parent[u] = p;
    for (int e = head[u]; e != 0; e = nxt[e]) {
        int v = to[e];
        if (!visited[v]) {
            if (dfs(v, u)) {
                return true;
            }
        } else if (v != p) {
            start_node = v;
            end_node = u;
            return true;
        }
    }
    return false;
}

void add_edge(int u, int v) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
    cnt++;
}

int main() {
    int n, m;
    cin >> n >> m;

    fill(head + 1, head + n + 1, 0);
    fill(visited + 1, visited + n + 1, 0);
    fill(parent + 1, parent + n + 1, -1);

    start_node = -1;
    end_node = -1;
    cnt = 1;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            break;
        }
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start_node);

        int node = end_node;
        while (node != start_node) {
            cycle.push_back(node);
            node = parent[node];
        }

        cycle.push_back(start_node);

        cout << cycle.size() << "\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}