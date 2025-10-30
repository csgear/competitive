// https://www.acwing.com/problem/content/2186/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1610;
const int M = 10000;
const int INF = 1e8;

struct Edge {
    int to, nxt;
    ll cap, cost;
} edges[M];

int head[N], cnt = -1;
int a[N];
ll dist[N], incf[N];
int pre[N];
bool inq[N];

int n, S, T;
int p, x, f, y, s;

void add_edge(int u, int v, ll cap, ll cost) {
    edges[++cnt] = {v, head[u], cap, cost};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(pre, -1, sizeof pre);
    memset(inq, 0, sizeof inq);
    memset(incf, 0, sizeof incf);
    dist[S] = 0;
    queue<int> q;
    q.push(S);
    incf[S] = INF;
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
    return incf[T] > 0;
}

pair<ll, ll> mcmf(int S, int T) {
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
    cin >> n >> p >> x >> f >> y >> s;

    memset(head, -1, sizeof head);
    S = 0, T = 2 * n + 1;

    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        add_edge(S, i, r, 0);                            // 每天会产出r[i]条旧毛巾
        add_edge(i + n, T, r, 0);                        // 每天需要r[i]条新毛巾
        add_edge(S, i + n, INF, p);                      // 每天可以购买若干条新毛巾，费用是p
        if (i + 1 <= n) add_edge(i, i + 1, INF, 0);      // 每天可以留若干条旧毛巾到下一天
        if (i + x <= n) add_edge(i, i + x + n, INF, f);  // 每天可以快洗若干条旧毛巾给x天后用，费用是f
        if (i + y <= n) add_edge(i, i + y + n, INF, s);  // 每天可以慢洗若干条旧毛巾给y天后用，费用是s
    }

    cout << mcmf(S, T).second << endl;
    return 0;
}
