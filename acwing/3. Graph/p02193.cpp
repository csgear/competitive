// https://www.acwing.com/problem/content/2195
// compute min cost max flow and max cost max flow
// set the cost of edges from left to right as positive for min cost
// and negative for max cost

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 250;
const int M = 25000;
const ll INF = 1e18;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];

int head[N], cnt = -1;
ll dist[N];
ll incf[N];
int pre[N];
bool inq[N];
int cost[N][N];

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa(int S, int T, int n) {
    fill(dist, dist + n + 1, INF);
    fill(inq, inq + n + 1, false);
    queue<int> q;
    dist[S] = 0;
    inq[S] = true;
    incf[S] = INF;
    q.push(S);

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

ll solve(int n, int S, int T, int sign) {
    memset(head, -1, sizeof head);
    cnt = -1;

    for (int i = 1; i <= n; i++) {
        add_edge(S, i, 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            add_edge(i, n + j, INF, sign * cost[i][j]);
        }
    }

    for (int j = 1; j <= n; j++) {
        add_edge(n + j, T, 1, 0);
    }

    return mcmf(S, T, T).second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    int S = 0, T = 2 * n + 1;

    ll min_cost = solve(n, S, T, 1);
    ll max_cost = solve(n, S, T, -1);

    cout << min_cost << endl;
    cout << -max_cost << endl;

    return 0;
}
