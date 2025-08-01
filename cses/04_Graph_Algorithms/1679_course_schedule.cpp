// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, nxt;
} edges[MAXN << 1];

int head[MAXN], cnt = 1;

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

vector<int> kahnTopologicalSort(int n, vector<int>& indegree) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

vector<int> dfsTopologicalSort(int n) {
    vector<int> result;
    vector<int> color(n + 1, 0);
    bool hasCycle = false;

    function<void(int)> dfs = [&](int u) -> void {
        color[u] = 1;

        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            if (color[v] == 1) {
                hasCycle = true;
                return;
            }
            if (color[v] == 0) {
                dfs(v);
            }
        }

        color[u] = 2;
        result.push_back(u);
    };

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (hasCycle) {
        return {};
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        indegree[v]++;
    }

    vector<int> topo = kahnTopologicalSort(n, indegree);

    if (topo.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << topo[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}