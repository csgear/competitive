// https://www.acwing.com/problem/content/288/
// https://www.luogu.com.cn/problem/P2014
// Tree DP: select courses with prerequisites to maximize credit
// State: f[u][j] = max credit from subtree u selecting j courses
// Knapsack on tree structure

#include <bits/stdc++.h>
using namespace std;

const int N = 310;

struct Edge {
    int to, nxt;
} edges[N];
int cnt = 1, head[N], w[N];
int f[N][N];

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

int n, m;

void dfs(int u) {
    f[u][1] = w[u];

    for (int i = head[u]; i; i = edges[i].nxt) {
        int v = edges[i].to;
        dfs(v);

        for (int j = m; j >= 1; j--) {
            for (int k = 1; k <= j - 1 && k <= m; k++) {
                if (f[v][k] > 0) {
                    f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> w[i];
        add_edge(p, i);
    }
    m++;
    dfs(0);

    cout << f[0][m] << endl;

    return 0;
}