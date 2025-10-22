// https://www.acwing.com/problem/content/259/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20010;
const int M = 200010;

struct Edge {
    int to, next;
    ll w;
} edges[M];

int head[N], cnt;
int color[N];
int n, m;

void add_edge(int u, int v, ll w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

bool dfs(int u, int c, int mid) {
    color[u] = c;
    for (int i = head[u]; i != 0; i = edges[i].next) {
        int v = edges[i].to;
        ll w = edges[i].w;
        if (w <= mid) continue;
        if (!color[v]) {
            if (!dfs(v, 3 - c, mid)) return false;
        } else if (color[v] == c) {
            return false;
        }
    }
    return true;
}

bool checkmid(ll v) {
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1, v)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    cnt = 1;

    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    ll l = 0, r = 1e9;

    while (l < r) {
        ll val = (l + r) >> 1;
        if (checkmid(val))
            r = val;
        else
            l = val + 1;
    }
    cout << l << "\n";
    return 0;
}