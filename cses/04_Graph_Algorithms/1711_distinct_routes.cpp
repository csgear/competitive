// https://cses.fi/problemset/task/1711
// Distinct Routes - Find k edge-disjoint paths from 1 to n

#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 2005;

struct edge {
    int v, nxt, cap, id;
} e[M];

int head[N], cnt = 1;
int dep[N], cur[N];
int n, m;
bool vis[M] = {0};

void add(int u, int v, int capacity, int edge_id = -1) {
    e[++cnt] = {v, head[u], capacity, edge_id};
    head[u] = cnt;
}

bool bfs() {
    memset(dep, 0, sizeof dep);
    queue<int> q;
    q.push(1);
    dep[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (dep[v] == 0 && e[i].cap > 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
                if (v == n) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int flow) {
    if (u == n) return flow;

    int used = 0;
    for (int& i = cur[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (dep[v] == dep[u] + 1 && e[i].cap > 0) {
            int pushed = dfs(v, min(flow - used, e[i].cap));
            if (pushed > 0) {
                e[i].cap -= pushed;
                e[i ^ 1].cap += pushed;
                used += pushed;
                if (used == flow) break;
            }
        }
    }
    if (used == 0) dep[u] = 0;
    return used;
}

int dinic() {
    int max_flow = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof head);
        max_flow += dfs(1, INT_MAX);
    }
    return max_flow;
}

vector<int> find_path() {
    vector<int> path = {1};
    int x = 1;

    while (x != n) {
        bool found = false;
        for (int i = head[x]; i; i = e[i].nxt) {
            int v = e[i].v;
            int edge_id = e[i].id;
            if (e[i].cap == 0 && edge_id > 0 && !vis[edge_id]) {
                path.push_back(v);
                x = v;
                vis[edge_id] = true;
                found = true;
                break;
            }
        }
        if (!found) break;
    }

    if (x == n) return path;
    return {};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v, 1, i + 1);  // Forward edge with capacity 1 and edge id
        add(v, u, 0);         // Reverse edge with capacity 0
    }

    int max_flow = dinic();

    cout << max_flow << '\n';

    for (int i = 0; i < max_flow; i++) {
        vector<int> path = find_path();

        cout << path.size() << '\n';
        for (size_t j = 0; j < path.size(); j++) {
            cout << path[j] << " \n"[j == path.size() - 1];
        }
    }

    return 0;
}
