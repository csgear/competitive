// https://cses.fi/problemset/task/2077

#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 200005;
int head[N], tot;
struct E {
    int to, nxt;
} e[2 * M];
void add(int u, int v) {
    e[tot] = {v, head[u]};
    head[u] = tot++;
}
int dfn[N], low[N], ts, root;
bool cut[N];
void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    int ch = 0;
    for (int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) {
            ch++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (u != root && low[v] >= dfn[u]) cut[u] = 1;
            if (u == root && ch >= 2) cut[u] = 1;
        } else
            low[u] = min(low[u], dfn[v]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    tot = 0;
    ts = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) root = i, tarjan(i);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += cut[i];
    cout << cnt << '\n';
    bool f = 1;
    for (int i = 1; i <= n; ++i)
        if (cut[i]) {
            if (!f) cout << ' ';
            cout << i;
            f = 0;
        }
    cout << '\n';
    return 0;
}
