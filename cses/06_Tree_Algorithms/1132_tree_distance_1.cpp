// https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge {
    int to, next;
} edges[MAXM];

int head[MAXN], tot = 0;

int d_a[MAXN], d_b[MAXN];

void add_edge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

void dfs(int u, int p, int dist[]) {
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u, dist);
    }
}

int find_farthest_node(int start, int n, int dist[]) {
    memset(dist, 0, sizeof(int) * MAXN);
    dfs(start, 0, dist);
    int max_distance = 0, max_distance_node = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > max_distance) {
            max_distance = dist[i];
            max_distance_node = i;
        }
    }
    return max_distance_node;
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
    int A = find_farthest_node(1, n, d_a);
    int B = find_farthest_node(A, n, d_a);
    dfs(B, 0, d_b);
    for (int i = 1; i <= n; i++) {
        cout << max(d_a[i], d_b[i]) << " ";
    }
    cout << endl;
    return 0;
}
