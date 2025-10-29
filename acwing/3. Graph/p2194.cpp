// https://www.acwing.com/problem/content/2196/
// compute min cost max flow and max cost max flow

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 110;
const int M = 1010;
const ll INF = 1e18;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];

int head[N], cnt = -1;
int a[N];
ll dist[N];
ll incf[N];
int pre[N];
bool inq[N];
int n, S, T;

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa(int S, int T, int n) {
    fill(dist, dist + n + 1, INF);
    fill(incf, incf + n + 1, 0);
    fill(pre, pre + n + 1, -1);
    fill(inq, inq + n + 1, false);
    dist[S] = 0;
    incf[S] = INF;
    queue<int> q;
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

pair<ll, ll> mcmf(int S, int T, int n) {
    ll max_flow = 0, min_cost = 0;
    while (spfa(S, T, n)) {
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

    cin >> n;

    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    ll avg = tot / n;

    int S = 0, T = n + 1;

    memset(head, -1, sizeof head);

    for (int i = 1; i <= n; i++) {
        int next = (i % n) + 1;
        add_edge(i, next, INF, 1);
        add_edge(next, i, INF, 1);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] > avg) {
            add_edge(S, i, a[i] - avg, 0);
        } else if (a[i] < avg) {
            add_edge(i, T, avg - a[i], 0);
        }
    }

    auto [flow, max_cost] = mcmf(S, T, T);

    cout << max_cost << endl;

    return 0;
}
