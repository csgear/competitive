// https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge {
    int to, next;
} edges[MAXM];

int head[MAXN], tot = 0;

int max_d = 0, max_d_node = 0;

void add_edge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

void dfs(int u, int p, int dist) {
    if (dist > max_d) {
        max_d = dist;
        max_d_node = u;
    }
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p) continue;
        dfs(v, u, dist + 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    // First DFS to find one end of the diameter
    max_d = 0;
    dfs(1, 0, 0);
    int first_end = max_d_node;

    // Second DFS from the first end to find the other end and diameter
    max_d = 0;
    dfs(first_end, 0, 0);

    cout << max_d << endl;
    return 0;
}