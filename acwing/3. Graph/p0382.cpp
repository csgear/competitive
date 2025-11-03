// https://www.acwing.com/problem/content/384/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5010;
const int M = 50010;
const ll INF = 1e18;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];
int head[N], cnt = -1;
ll dist[N], incf[N], pre[N];
bool inq[N];

int cost[55][55];
int n, k, S, T;

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

// map (x, y, t) to node id, t = 0 for in-node, t = 1 for out-node
int f(int x, int y, int t) { return (x * n + y) * 2 + t; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    memset(head, -1, sizeof head);
    cnt = -1;

    S = 2 * n * n, T = S + 1;

    add_edge(S, f(0, 0, 0), k, 0);
    add_edge(f(n - 1, n - 1, 1), T, k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            add_edge(f(i, j, 0), f(i, j, 1), 1, -x);
            add_edge(f(i, j, 0), f(i, j, 1), INF, 0);
            if (i < n - 1) add_edge(f(i, j, 1), f(i + 1, j, 0), INF, 0);
            if (j < n - 1) add_edge(f(i, j, 1), f(i, j + 1, 0), INF, 0);
        }
    }

    cout << -mfcf(S, T).second << endl;

    return 0;
}