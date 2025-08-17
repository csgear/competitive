// https://cses.fi/problemset/task/1137

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
vector<int> adj[N];
ll a[N];
ll tree[N];
int in_time[N], out_time[N];
int timer_cnt = 0;

int lowbit(int x) { return x & -x; }

void update(int i, ll val) {
    for (; i < N; i += lowbit(i)) {
        tree[i] += val;
    }
}

ll query(int i) {
    ll res = 0;
    for (; i > 0; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}

ll range_query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
}

void dfs(int u, int p) {
    in_time[u] = ++timer_cnt;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out_time[u] = timer_cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        update(in_time[i], a[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            ll x;
            cin >> u >> x;
            ll old_val = a[u];
            update(in_time[u], x - old_val);
            a[u] = x;
        } else {
            int u;
            cin >> u;
            cout << range_query(in_time[u], out_time[u]) << "\n";
        }
    }

    return 0;
}