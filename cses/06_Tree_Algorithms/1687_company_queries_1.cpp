// https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> children[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int d) {
    depth[u] = d;
    for (int v : children[u]) {
        dfs(v, d + 1);
    }
}

void preprocess(int n) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            } else {
                parent[i][j] = -1;
            }
        }
    }
}

int kth_ancestor(int u, int k) {
    if (k > depth[u]) return -1;

    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = parent[u][i];
            if (u == -1) return -1;
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LOG; j++) {
            parent[i][j] = -1;
        }
    }

    parent[1][0] = -1;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        parent[i][0] = p;
        children[p].push_back(i);
    }

    dfs(1, 0);

    preprocess(n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << kth_ancestor(x, k) << '\n';
    }

    return 0;
}