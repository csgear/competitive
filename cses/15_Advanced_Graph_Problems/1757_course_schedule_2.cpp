// https://cses.fi/problemset/task/1757

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e5 + 5;

int n, m, outdeg[N], head[N], to[M], nxt[M], cnt;
vector<int> order;
priority_queue<int> q;

inline void add_edge(int u, int v) {
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        add_edge(v, u);
        ++outdeg[u];
    }
    for (int i = 1; i <= n; ++i)
        if (outdeg[i] == 0) q.emplace(i);

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        order.emplace_back(u);
        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];
            if (--outdeg[v] == 0) q.emplace(v);
        }
    }
    reverse(order.begin(), order.end());

    for (int u : order) cout << u << " ";

    return 0;
}
