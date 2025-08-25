// https://cses.fi/problemset/task/2076
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
int dfn[N], low[N], ts;
bool br[2 * M];
void tarjan(int u, int in_e) {
    dfn[u] = low[u] = ++ts;
    for (int i = head[u]; ~i; i = e[i].nxt) {
        if (i == (in_e ^ 1)) continue;
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) br[i] = br[i ^ 1] = 1;
        } else
            low[u] = min(low[u], dfn[v]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    tot = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i, -1);
    vector<pair<int, int>> ans;
    for (int i = 0; i < tot; i += 2)
        if (br[i]) ans.emplace_back(e[i ^ 1].to, e[i].to);
    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.first << ' ' << p.second << '\n';
    return 0;
}
