// https://www.acwing.com/problem/content/2281/
// 0-1 fractional programming - parametric search on flow ratio
// Binary search on ratio mid, reduce edge capacities by mid, check if flow ≤ 0
// Finds optimal ratio using Dinic's algorithm for each iteration

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 410 * 2;
const double INF = 1e10;
const double eps = 1e-6;

struct Edge {
    int to, nxt;
    double cap;
} edges[M];

int head[N], cnt;
int d[N], cur[N];
int n, m, S, T;

vector<tuple<int, int, double>> original_edges;

void add_edge(int u, int v, double cap) {
    edges[cnt] = {v, head[u], cap};
    head[u] = cnt++;
    edges[cnt] = {u, head[v], cap};
    head[v] = cnt++;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    d[S] = 0;
    q.push(S);
    cur[S] = head[S];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            if (d[v] == -1 && edges[i].cap > eps) {
                d[v] = d[u] + 1;
                cur[v] = head[v];
                if (v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

double dfs(int u, double limit) {
    if (u == T) return limit;
    double flow = 0;
    for (int i = cur[u]; i != -1 && flow < limit; i = edges[i].nxt) {
        cur[u] = i;
        int v = edges[i].to;
        if (d[v] == d[u] + 1 && edges[i].cap > eps) {
            double t = dfs(v, min(limit - flow, edges[i].cap));
            if (t > eps) {
                edges[i].cap -= t;
                edges[i ^ 1].cap += t;
                flow += t;
            } else {
                d[v] = -1;
            }
        }
    }
    return flow;
}

double dinic(double mid) {
    cnt = 0;
    memset(head, -1, sizeof head);
    double res = 0;

    for (auto& [u, v, w] : original_edges) {
        double cap = w - mid;
        if (cap > eps) {
            add_edge(u, v, cap);
        } else {
            res += cap;
        }
    }

    double maxFlow = 0, flow;
    while (bfs()) {
        while ((flow = dfs(S, INF)) > eps) {
            maxFlow += flow;
        }
    }

    return maxFlow + res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> S >> T;

    for (int i = 1; i <= m; i++) {
        int u, v;
        double cap;
        cin >> u >> v >> cap;
        original_edges.emplace_back(u, v, cap);
    }

    double l = 0, r = 1e7;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (dinic(mid) <= 0) {
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%.2lf\n", l);
    return 0;
}