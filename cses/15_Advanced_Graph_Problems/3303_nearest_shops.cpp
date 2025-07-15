// https://cses.fi/problemset/task/3303

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge {
    int to, nxt;
} edges[MAXM << 1];

int head[MAXN], cnt = 0;

set<int> shops;

int addEdge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        shops.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    return 0;
}