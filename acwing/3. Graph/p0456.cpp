// https://www.acwing.com/problem/content/458/
// 456. 车站分级

#include <bits/stdc++.h>
using namespace std;

const int N = 3010, M = 1000010;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], idx = -1;
int d[N], dist[N];
bool st[N];

int n, m;

void add_edge(int u, int v, int w) {
    edges[++idx] = {v, head[u], w};
    head[u] = idx;
}

void toposort() {
    queue<int> q;
    for (int i = 1; i <= n + m; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            int w = edges[i].w;
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int cnt;
        cin >> cnt;

        memset(st, 0, sizeof st);

        int start = n + 1, end = 0;
        for (int j = 0; j < cnt; j++) {
            int u;
            cin >> u;
            st[u] = true;
            start = min(start, u);
            end = max(end, u);
        }

        int vir = n + i;

        for (int j = start; j <= end; j++) {
            if (st[j]) {
                add_edge(vir, j, 1);
                d[j]++;
            } else {
                add_edge(j, vir, 0);
                d[vir]++;
            }
        }
    }
    toposort();

    cout << *max_element(dist + 1, dist + n + 1) << endl;

    return 0;
}