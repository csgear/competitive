// https://cses.fi/problemset/task/1138

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int in[MAXN], out[MAXN];
int timer = 0;
ll val[MAXN];
ll tree[MAXN];
int n, q;

int lowbit(int x) { return x & -x; }

void dfs(int u, int parent) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
    out[u] = timer;
}

void update(int idx, ll delta) {
    for (; idx <= n; idx += lowbit(idx)) tree[idx] += delta;
}

ll query(int idx) {
    ll res = 0;
    for (; idx > 0; idx -= lowbit(idx)) res += tree[idx];
    return res;
}

void range_add(int l, int r, ll delta) {
    update(l, delta);
    if (r + 1 <= n) update(r + 1, -delta);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        range_add(in[i], out[i], val[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            range_add(in[s], out[s], x - val[s]);
            val[s] = x;
        } else {
            int s;
            cin >> s;
            cout << query(in[s]) << '\n';
        }
    }

    return 0;
}