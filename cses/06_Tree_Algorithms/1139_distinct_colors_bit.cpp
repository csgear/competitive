// https://cses.fi/problemset/task/1139/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int out[MAXN], color[MAXN], ans[MAXN], in[MAXN];
int tree[MAXN];
int timer = 1, n;

// Euler tour
void dfs(int u, int p) {
    in[u] = timer;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    out[timer] = u;
    timer++;
}

int lowbit(int x) { return x & -x; }

void update(int i, int val) {
    while (i <= n) {
        tree[i] += val;
        i += lowbit(i);
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res += tree[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    map<int, int> last;
    for (int i = 1; i <= n; i++) {
        int c = color[out[i]];

        if (last.count(c)) {
            update(last[c], -1);
        }

        last[c] = i;
        update(i, 1);

        ans[out[i]] = query(i) - query(in[out[i]] - 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}