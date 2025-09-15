// https://atcoder.jp/contests/abc404/tasks/abc404_g

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 4005;

struct Edge {
    int u, v, w;
} edge[N * 10];

int cnt = 0;
ll dist[N];

int n, m;

void addEdge(int u, int v, int w) { edge[++cnt] = {u, v, w}; }

ll bellman_ford() {
    for (int i = 0; i <= n; i++) dist[i] = -1e18;

    dist[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        bool flag = false;
        for (int j = 1; j <= cnt; j++) {
            Edge e = edge[j];
            if (dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                flag = true;
            }
        }
        if (!flag) return dist[n];
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        addEdge(l - 1, r, s);
        addEdge(r, l - 1, -s);
    }
    for (int i = 0; i < n; i++) {
        addEdge(i, i + 1, 1);
    }
    for (int i = 1; i <= n; i++) {
        addEdge(0, i, 0);
    }

    cout << bellman_ford() << endl;
    return 0;
}