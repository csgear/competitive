// https://www.acwing.com/problem/content/1176/
// Strongly connected components - Tarjan's algorithm
// Find SCCs, build condensed DAG, count sources and sinks
// Answer = max(sources, sinks) edges needed for strong connectivity

// To make a directed graph strongly connected, let p be the number of strongly connected components
// with in-degree zero (sources), and q the number with out-degree zero (sinks) in the condensed
// DAG. Then, the minimum number of edges that must be added is: max(p, q).
// If the graph is already strongly connected (i.e., p = q = 0),

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 5e4 + 10;

struct Edge {
    int to, nxt;
} edges[M];

int head[N], edge_cnt = 1;
int n, m;

int dfn[N], low[N], timestamp;
bool in_stack[N];
int scc_size[N], out_degree[N], scc_cnt, scc_id[N];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    in_stack[u] = true;
    for (int i = head[u]; i; i = edges[i].nxt) {
        int v = edges[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scc_cnt++;
        int y;
        do {
            y = stk.top();
            stk.pop();
            in_stack[y] = false;
            scc_id[y] = scc_cnt;
            scc_size[scc_cnt]++;
        } while (y != u);
    }
}

void add_edge(int u, int v) {
    edges[edge_cnt] = {v, head[u]};
    head[u] = edge_cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to;
            if (scc_id[u] != scc_id[v]) {
                out_degree[scc_id[u]]++;
            }
        }
    }

    int ans = 0, zeros = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (out_degree[i] == 0) {
            ans += scc_size[i];
            zeros++;
        }
        if (zeros > 1) {
            ans = 0;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
