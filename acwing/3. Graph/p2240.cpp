// https://www.acwing.com/problem/content/2242/

#include <bits/stdc++.h>
using namespace std;

const int N = 410;
// 100 cows * 100 food + 100 cows * 100 drinks + split vertex + super source/sink
const int M = (100 * 100 * 2 + 3 * 100 + 10) * 2;
const int INF = 1e8;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];
int n, m1, m2, S, T;

void add_edge(int u, int v, int cap) {
    edges[++cnt] = {v, head[u], cap};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0};
    head[v] = cnt;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    d[S] = 0;
    cur[S] = head[S];
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (d[v] == -1 && edges[i].cap > 0) {
                d[v] = d[u] + 1;
                cur[v] = head[v];
                if (v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dfs(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; i != -1 && flow < limit; i = edges[i].nxt) {
        cur[u] = i;
        int v = edges[i].to;
        if (d[v] == d[u] + 1 && edges[i].cap > 0) {
            int t = dfs(v, min(limit - flow, edges[i].cap));
            if (t == 0) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}
int dinic() {
    int maxFlow = 0;
    while (bfs()) {
        int flow;
        while ((flow = dfs(S, INF)) > 0) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m1 >> m2;

    S = 0;
    T = 2 * n + m1 + m2 + 1;

    for (int i = 1; i <= m1; i++) {
        add_edge(S, 2 * n + i, 1);
    }

    for (int i = 1; i <= m2; i++) {
        add_edge(2 * n + m1 + i, T, 1);
    }

    for (int i = 1; i <= n; i++) {
        add_edge(i, i + n, 1);
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= a; j++) {
            int food;
            cin >> food;
            add_edge(2 * n + food, i, 1);
        }

        for (int j = 1; j <= b; j++) {
            int drink;
            cin >> drink;
            add_edge(i + n, 2 * n + m1 + drink, 1);
        }
    }

    cout << dinic() << endl;

    return 0;
}
