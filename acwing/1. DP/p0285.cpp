// https://www.acwing.com/problem/content/287/
// 285. 没有上司的舞会

#include <bits/stdc++.h>
using namespace std;

// this is a tree, M = N - 1
const int N = 6000 + 10, M = N;

struct Edge {
    int to, next;
} edges[M];

int head[N], idx = -1;
int w[N];
int f[N][2];  // f[u][0]表示u不参加，f[u][1]表示u参加
int n;
bool has_father[N];

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

void dfs(int u) {
    f[u][0] = 0;
    f[u][1] = w[u];

    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    memset(head, -1, sizeof head);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(b, a);
        has_father[a] = true;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (!has_father[i]) {
            root = i;
            break;
        }
    }

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}