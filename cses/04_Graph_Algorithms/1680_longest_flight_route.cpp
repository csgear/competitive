// https://cses.fi/problemset/task/1680

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

int main() {
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

    vector<int> dp(n + 1, 0);
    vector<int> parent(n + 1, -1);

    dp[1] = 1;

    for (int u : topo) {
        if (dp[u] == 0) continue;
        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == 0) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << dp[n] << '\n';

        vector<int> path;
        int cur = n;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}