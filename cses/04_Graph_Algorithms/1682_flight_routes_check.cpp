// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, nxt;
} edges[MAXN << 2], redges[MAXN << 2];

int head[MAXN], rhead[MAXN], cnt = 1, rcnt = 1;

void addEdge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;

    redges[rcnt] = {u, rhead[v]};
    rhead[v] = rcnt++;
}

bool visited[MAXN];
vector<int> order;

void dfs1(int u) {
    visited[u] = true;
    for (int i = head[u]; i; i = edges[i].nxt) {
        int v = edges[i].to;
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (int i = rhead[u]; i; i = redges[i].nxt) {
        int v = redges[i].to;
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    fill(visited, visited + n + 1, false);
    int scc_count = 0;

    for (int i = order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (!visited[u]) {
            dfs2(u);
            scc_count++;
        }
    }

    if (scc_count == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        fill(visited, visited + n + 1, false);
        dfs2(order.back());

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << i << " " << order.back() << "\n";
                break;
            }
        }
    }

    return 0;
}