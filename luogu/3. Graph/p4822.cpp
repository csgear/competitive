// https://www.luogu.com.cn/problem/P4822
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 2010;
const int K = 55;
const int INF = 0x3f3f3f3f;

int n, m, k, S, T;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt = -1;
int d[N][K], st[N][K];  // st[u][i]: 是否在队列中

void add_edge(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

// Dijkstra
int dijkstra() {
    memset(d, 0x3f, sizeof d);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    d[S][0] = 0;
    pq.push({0, S, 0});

    while (!pq.empty()) {
        auto [dist, u, used_k] = pq.top();
        pq.pop();

        if (dist != d[u][used_k]) continue;  // 过期状态

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            int w = edges[i].w;

            // 不使用卡
            if (d[v][used_k] > d[u][used_k] + w) {
                d[v][used_k] = d[u][used_k] + w;
                pq.push({d[v][used_k], v, used_k});
            }

            // 使用卡
            if (used_k < k) {
                int new_cost = d[u][used_k] + w / 2;
                if (d[v][used_k + 1] > new_cost) {
                    d[v][used_k + 1] = new_cost;
                    pq.push({d[v][used_k + 1], v, used_k + 1});
                }
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= k; i++) {
        res = min(res, d[T][i]);
    }
    return res;
}

// SPFA
int spfa() {
    memset(d, 0x3f, sizeof d);
    memset(st, 0, sizeof st);

    queue<pair<int, int>> q;
    d[S][0] = 0;
    q.push({S, 0});
    st[S][0] = true;

    while (!q.empty()) {
        auto [u, used_k] = q.front();
        q.pop();
        st[u][used_k] = false;

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            int w = edges[i].w;

            if (d[v][used_k] > d[u][used_k] + w) {
                d[v][used_k] = d[u][used_k] + w;
                if (!st[v][used_k]) {
                    q.push({v, used_k});
                    st[v][used_k] = true;
                }
            }

            if (used_k < k) {
                int new_cost = d[u][used_k] + w / 2;
                if (d[v][used_k + 1] > new_cost) {
                    d[v][used_k + 1] = new_cost;
                    if (!st[v][used_k + 1]) {
                        q.push({v, used_k + 1});
                        st[v][used_k + 1] = true;
                    }
                }
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= k; i++) {
        res = min(res, d[T][i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    S = 1, T = n;

    int res = spfa();

    cout << res << endl;
    return 0;
}