// https://cses.fi/problemset/task/1694
// Dinic's Algorithm for Maximum Flow

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 505;
const int M = 2005;

struct edge {
    LL v, nxt, cap;
} e[M];

int head[N], cnt = 1;
int dep[N], cur[N];
int S, T;

void add(int u, int v, int cap) {
    // index starts from 2
    // even edge from u -> v, odd edge from v -> u
    e[++cnt] = {v, head[u], cap};
    head[u] = cnt;
}

bool bfs() {
    memset(dep, 0, sizeof dep);
    queue<int> q;
    q.push(S);
    dep[S] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (dep[v] == 0 && e[i].cap) {
                dep[v] = dep[u] + 1;
                q.push(v);
                if (v == T) return true;
            }
        }
    }
    return false;
}

LL dfs(int u, LL mf) {
    if (u == T) return mf;
    LL sum = 0;
    for (int i = cur[u]; i; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].v;
        if (dep[v] == dep[u] + 1 && e[i].cap) {
            LL f = dfs(v, min(mf, e[i].cap));
            e[i].cap -= f;
            e[i ^ 1].cap += f;
            sum += f;
            mf -= f;
            if (mf == 0) break;
        }
    }
    if (sum == 0) dep[u] = 0;
    return sum;
}

LL dinic() {
    LL flow = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof head);
        flow += dfs(S, 1e9);
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    S = 1;
    T = n;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }

    cout << dinic() << '\n';

    return 0;
}
