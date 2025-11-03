// https://www.acwing.com/problem/content/2197/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 260;
const int M = 2010;
const ll INF = 1e9;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];

int head[N], cnt = -1;
ll dist[N], incf[N];
int pre[N];
bool inq[N];

int n, m, S, T;

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa() {
    fill(dist, dist + N, -INF);
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
            if (edges[i].cap > 0 && dist[v] < dist[u] + edges[i].cost) {
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
    return incf[T] > 0;
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

int f(int i, int j) { return i * (m + 1) + j; }

int main() {
    int A, B;
    cin >> A >> B >> n >> m;
    S = (n + 1) * (m + 1), T = S + 1;
    memset(head, -1, sizeof head);
    cnt = -1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            add_edge(f(i, j), f(i, j + 1), 1, c);
            add_edge(f(i, j), f(i, j + 1), INF, 0);
        }
    }
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            add_edge(f(i, j), f(i + 1, j), 1, c);
            add_edge(f(i, j), f(i + 1, j), INF, 0);
        }
    }

    for (int i = 0; i < A; i++) {
        int k, x, y;
        cin >> k >> x >> y;
        add_edge(S, f(x, y), k, 0);
    }

    for (int i = 0; i < B; i++) {
        int k, x, y;
        cin >> k >> x >> y;
        add_edge(f(x, y), T, k, 0);
    }

    cout << mfcf(S, T).second << endl;

    return 0;
}