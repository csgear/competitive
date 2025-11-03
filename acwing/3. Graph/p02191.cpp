// https://www.acwing.com/problem/content/2193/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 原点数 （600）+ 拆点（600）+ 源点+汇点
const int N = 1210;
// 拆点 N + 联边 N * 2
const int M = 8000;
const ll INF = 1e18;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];
int head[N], cnt = -1;
int s, t, S, T;
ll dist[N], incf[N], pre[N];
bool inq[N];

int cost[50][50], id[50][50];

int n, m;

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa() {
    fill(dist, dist + N, INF);
    fill(incf, incf + N, 0);
    fill(pre, pre + N, -1);
    fill(inq, inq + N, false);
    queue<int> q;
    dist[S] = 0;
    incf[S] = INF;
    q.push(S);
    inq[S] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (edges[i].cap > 0 && dist[v] > dist[u] + edges[i].cost) {
                dist[v] = dist[u] + edges[i].cost;
                pre[v] = i;
                incf[v] = min(incf[u], edges[i].cap);
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return dist[T] != INF;
}

pair<ll, ll> mfcf(int S, int T) {
    ll max_flow = 0, min_cost = 0;
    while (spfa()) {
        ll flow = incf[T];
        for (int i = T; i != S; i = edges[pre[i] ^ 1].to) {
            edges[pre[i]].cap -= flow;
            edges[pre[i] ^ 1].cap += flow;
        }
        max_flow += flow;
        min_cost += flow * dist[T];
    }
    return {max_flow, min_cost};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    int idx = 0;
    S = ++idx;
    T = ++idx;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + i - 1; j++) {
            cin >> cost[i][j];
            id[i][j] = ++idx;
        }
    }

    // 规则1: 所有路径的点和边都不能相交，即所有点和所有边都只能走一次
    memset(head, -1, sizeof head);
    cnt = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + i - 1; j++) {
            add_edge(id[i][j] * 2, id[i][j] * 2 + 1, 1, -cost[i][j]);
            if (i == 1) {
                add_edge(S, id[i][j] * 2, 1, 0);
            }
            if (i == n) {
                add_edge(id[i][j] * 2 + 1, T, 1, 0);
            }
            if (i < n) {
                add_edge(id[i][j] * 2 + 1, id[i + 1][j] * 2, 1, 0);
                add_edge(id[i][j] * 2 + 1, id[i + 1][j + 1] * 2, 1, 0);
            }
        }
    }

    cout << -mfcf(S, T).second << endl;

    // 规则2: 所有路径的边都不能相交，即所有边只能走一次，所有点可以走无数次
    memset(head, -1, sizeof head);
    cnt = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + i - 1; j++) {
            add_edge(id[i][j] * 2, id[i][j] * 2 + 1, INF, -cost[i][j]);
            if (i == 1) {
                add_edge(S, id[i][j] * 2, 1, 0);
            }
            if (i == n) {
                add_edge(id[i][j] * 2 + 1, T, INF, 0);
            }
            if (i < n) {
                add_edge(id[i][j] * 2 + 1, id[i + 1][j] * 2, 1, 0);
                add_edge(id[i][j] * 2 + 1, id[i + 1][j + 1] * 2, 1, 0);
            }
        }
    }

    cout << -mfcf(S, T).second << endl;

    // 规则3: 所有路径的点和边都可以相交，即所有点和所有边都可以走无数次
    memset(head, -1, sizeof head);
    cnt = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + i - 1; j++) {
            add_edge(id[i][j] * 2, id[i][j] * 2 + 1, INF, -cost[i][j]);
            if (i == 1) {
                add_edge(S, id[i][j] * 2, 1, 0);
            }
            if (i == n) {
                add_edge(id[i][j] * 2 + 1, T, INF, 0);
            }
            if (i < n) {
                add_edge(id[i][j] * 2 + 1, id[i + 1][j] * 2, INF, 0);
                add_edge(id[i][j] * 2 + 1, id[i + 1][j + 1] * 2, INF, 0);
            }
        }
    }

    cout << -mfcf(S, T).second << endl;

    return 0;
}