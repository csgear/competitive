// https://cses.fi/problemset/task/2079

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge {
    int to, next;
} edges[MAXM];

int head[MAXN], tot = 0;

int d[MAXN], ans[MAXN], centroid_count = 0, maxnum = 1e9;
int total_nodes;

void add_edge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

void dfs(int u, int p) {
    d[u] = 1;
    int max_subtree_size = 0;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p) continue;
        dfs(v, u);
        d[u] += d[v];
        max_subtree_size = max(max_subtree_size, d[v]);
    }
    // Calculate the size of the subtree that would remain if we remove node u
    int remaining_size = total_nodes - d[u];
    max_subtree_size = max(max_subtree_size, remaining_size);

    if (max_subtree_size < maxnum) {
        maxnum = max_subtree_size;
        centroid_count = 0;
        ans[++centroid_count] = u;
    } else if (max_subtree_size == maxnum) {
        ans[++centroid_count] = u;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    total_nodes = n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    // cout << centroid_count << endl;
    // for (int i = 1; i <= centroid_count; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    cout << ans[1] << endl;
    return 0;
}