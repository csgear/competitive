// https://www.acwing.com/problem/content/2280/

#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 210;
const int M = 20510;
const int INF = 1e8;
const double eps = 1e-5;

struct Edge {
    int to, nxt, cap;
} edges[M];

int head[N], cnt = -1;
int d[N], cur[N];
PII pt[N * N];

int n, S, T;
double D;
int tot = 0;

bool check(const PII& a, const PII& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    double dist = dx * dx + dy * dy;
    return dist < D * D + eps;
}

void addEdge(int u, int v, int cap) {
    edges[++cnt] = {v, head[u], cap};
    head[u] = cnt;
    edges[++cnt] = {u, head[v], 0};
    head[v] = cnt;
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
            if (!t) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}

int dinic() {
    int res = 0, flow;
    while (bfs())
        while (flow = dfs(S, INF)) res += flow;
    return res;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        memset(head, -1, sizeof head);
        cnt = -1;
        cin >> n >> D;
        S = 0;
        tot = 0;

        for (int i = 1; i <= n; i++) {
            int xi, yi, ni, mi;
            cin >> xi >> yi >> ni >> mi;
            pt[i] = {xi, yi};
            addEdge(S, i, ni);
            addEdge(i, i + n, mi);
            tot += ni;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (check(pt[i], pt[j])) {
                    addEdge(i + n, j, INF);
                    addEdge(j + n, i, INF);
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            T = i;
            for (int j = 0; j < cnt; j += 2) {
                edges[j].cap += edges[j ^ 1].cap;
                edges[j ^ 1].cap = 0;
            }
            int flow = dinic();
            if (flow == tot) {
                cout << i - 1 << " ";
                ans++;
            }
        }
        if (ans == 0) cout << -1;
        cout << endl;
    }

    return 0;
}