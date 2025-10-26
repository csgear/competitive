// https://www.acwing.com/problem/content/397/

// To make the graph connected, the minimum number of edges that need to be added is given by:
// ( c + 1 ) / 2
// where c is the number of connected components with degree one in the condensed tree

#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int M = 20010;

struct Edge {
    int to, nxt;
} edges[M];
int head[N], edge_cnt = 2;
int n, m;

int dfn[N], low[N], timestamp;
stack<int> stk;
int id[N], dcc_cnt;
bool is_bridge[M];
int degree[N];

void add_edge(int u, int v) {
    edges[edge_cnt] = {v, head[u]};
    head[u] = edge_cnt++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);

    for (int e = head[u]; e; e = edges[e].nxt) {
        int v = edges[e].to;
        if (!dfn[v]) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            // for edge (x,y) if low[x] < dfn[y], then (x,y) is a bridge
            if (low[v] > dfn[u]) {
                is_bridge[e] = is_bridge[e ^ 1] = true;
            }
        } else if (e != (from ^ 1)) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        dcc_cnt++;
        int y;
        do {
            y = stk.top();
            stk.pop();
            id[y] = dcc_cnt;
        } while (y != u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    // use 1-based edge indexing for XOR trick
    // edge_cnt starts from 2
    tarjan(1, 0);

    for (int i = 2; i < edge_cnt; i++) {
        if (is_bridge[i]) {
            int v = edges[i].to;
            degree[id[v]]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= dcc_cnt; i++) {
        if (degree[i] == 1) {
            ans++;
        }
    }

    cout << (ans + 1) / 2 << "\n";

    return 0;
}