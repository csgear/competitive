// https://www.acwing.com/problem/content/2189/
// Time-layered max flow with connectivity check
// Union-find checks initial reachability, then builds time-expanded graph
// Incrementally adds edges for each day until target flow reached

#include <bits/stdc++.h>
using namespace std;

// Max day 15 per person * 50 * 15 stations + super source/sink
const int N = (50 * 15 * 15 + 2) + 10, M = (N + 50 * 15 + 15 * 1000) * 2 + 10, INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt;
    int cap;
} edges[M];

// ship # <= 20
struct Ship {
    int h, r, id[20];
} ships[30];

int head[N], cnt = -1;
int d[N], cur[N];

int parent[25];

int n, m, K, S, T;

int get(int day, int id) { return day * (n + 2) + id; }

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

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
            if (!t) d[v] = -1;
            edges[i].cap -= t;
            edges[i ^ 1].cap += t;
            flow += t;
        }
    }
    return flow;
}

int dinic() {
    int maxflow = 0;
    while (bfs()) {
        while (int flow = dfs(S, INF)) {
            maxflow += flow;
        }
    }
    return maxflow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> n >> m >> K;

    S = N - 2;
    T = N - 1;

    for (int i = 0; i <= n + 1; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> ships[i].h >> ships[i].r;
        for (int j = 0; j < ships[i].r; j++) {
            int id;
            cin >> id;
            if (id == -1) id = n + 1;
            ships[i].id[j] = id;
            if (j) {
                int u = find(ships[i].id[j - 1]);
                int v = find(ships[i].id[j]);
                if (u != v) {
                    parent[u] = v;
                }
            }
        }
    }

    if (find(0) != find(n + 1)) {
        cout << 0 << "\n";
    } else {
        add_edge(S, get(0, 0), K);
        add_edge(get(0, n + 1), T, INF);
        int day = 1;
        int res = 0;
        while (true) {
            add_edge(get(day, n + 1), T, INF);
            for (int i = 0; i <= n + 1; i++) {
                add_edge(get(day - 1, i), get(day, i), INF);
            }
            for (int i = 0; i < m; i++) {
                int r = ships[i].r;
                int a = ships[i].id[(day - 1) % r];
                int b = ships[i].id[day % r];
                add_edge(get(day - 1, a), get(day, b), ships[i].h);
            }
            res += dinic();
            if (res >= K) break;
            day++;
        }
        cout << day << "\n";
    }
    return 0;
}