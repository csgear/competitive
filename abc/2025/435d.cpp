// https://atcoder.jp/contests/abc435/tasks/abc435_d
// D - Reachability Query 2

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, M = 3e5 + 10;

struct Edge {
    int to, next;
} edge[M];

int head[N], idx = -1;
bool st[N];

int n, m, q;

void add(int u, int v) {
    edge[++idx] = {v, head[u]};
    head[u] = idx;
}

void dfs(int u) {
    if (st[u]) return;
    st[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!st[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(v, u);
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int op, v;
        cin >> op >> v;
        if (op == 1) {
            dfs(v);
        } else {
            if (st[v]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}