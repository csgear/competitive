// https://www.acwing.com/problem/content/2173/
// Maximum flow - Edmonds-Karp algorithm (BFS-based Ford-Fulkerson)
// Finds augmenting paths using BFS, updates residual graph
// Time: O(VE²), suitable for smaller graphs

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int M = 200010;

struct Edge {
    int to, nxt, capacity;
} edges[M];

int head[N], cnt = -1;

void add_edge(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

int n, m, S, T;
int pre[N];
bool vis[N];

bool bfs() {
    memset(vis, false, sizeof vis);
    memset(pre, -1, sizeof pre);
    queue<int> q;
    q.push(S);
    vis[S] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (!vis[v] && edges[i].capacity > 0) {
                vis[v] = true;
                pre[v] = i;
                q.push(v);
                if (v == T) return true;
            }
        }
    }
    return false;
}

int ek() {
    int max_flow = 0;

    while (bfs()) {
        int min_flow = INT_MAX;

        for (int i = pre[T]; i != -1; i = pre[edges[i ^ 1].to]) {
            min_flow = min(min_flow, edges[i].capacity);
        }

        for (int i = pre[T]; i != -1; i = pre[edges[i ^ 1].to]) {
            edges[i].capacity -= min_flow;
            edges[i ^ 1].capacity += min_flow;
        }

        max_flow += min_flow;
    }

    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> S >> T;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }

    cout << ek() << endl;

    return 0;
}