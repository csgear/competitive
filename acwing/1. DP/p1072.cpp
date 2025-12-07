#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
using ll = long long;

struct Edge {
    int to, nxt;
    ll w;
} edges[N * 2];

int head[N], cnt = -1;

void add_edge(int u, int v, ll w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

ll diameter = LLONG_MIN;

ll dfs(int u, int parent) {
    ll d1 = 0;
    ll d2 = 0;

    for (int i = head[u]; i != -1; i = edges[i].nxt) {
        int v = edges[i].to;
        if (v == parent) continue;

        ll d = dfs(v, u) + edges[i].w;

        if (d > d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }

    diameter = max(diameter, d1 + d2);

    return d1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof(head));

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dfs(1, -1);
    cout << diameter << '\n';

    return 0;
}