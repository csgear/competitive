// https://www.luogu.com.cn/problem/P4878

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1e8;

struct Edge {
    int to, nxt;
    int w;
} edge[MAXN << 1];

int head[MAXN], cnt = 0;
int dist[MAXN];
int times[MAXN];
bool in_queue[MAXN];
int n, ml, md;

void add_edge(int u, int v, int w) {
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

int spfa(int start) {
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        times[i] = 0;
        in_queue[i] = false;
    }

    queue<int> q;
    dist[start] = 0;
    q.push(start);
    in_queue[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        times[u]++;
        in_queue[u] = false;

        if (times[u] > n) {
            return -1;  // Negative cycle detected
        }

        for (int i = head[u]; i != -1; i = edge[i].nxt) {
            int v = edge[i].to;
            int w = edge[i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    if (dist[n] == INF) {
        return -2;  // Unreachable
    }
    return dist[n];
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> ml >> md;

    for (int i = 1; i < n; i++) {
        add_edge(i + 1, i, 0);
    }

    for (int i = 0; i < ml; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    for (int i = 0; i < md; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(v, u, -w);
    }

    // Add virtual source to all nodes
    for (int i = 1; i <= n; i++) {
        add_edge(0, i, 0);
    }

    int result = spfa(0);
    if (result <= -1) {
        cout << result << endl;
    } else {
        cout << spfa(1) << endl;
    }

    return 0;
}
