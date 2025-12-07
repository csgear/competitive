// https://www.acwing.com/problem/content/166/
// 164. 可达性统计

#include <bits/stdc++.h>
using namespace std;

const int N = 30010, M = 30010;

struct Edge {
    int to, next;
} edges[M];
int head[N], idx = -1;
int d[N];
vector<int> topo;
bitset<N> f[N];
int n, m;

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

void topsort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            d[v]--;
            if (d[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        d[v]++;
    }

    topsort();

    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        f[u][u] = 1;
        for (int j = head[u]; j != -1; j = edges[j].next) {
            int v = edges[j].to;
            f[u] |= f[v];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i].count() << endl;
    }

    return 0;
}