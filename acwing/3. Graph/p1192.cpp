// https://www.acwing.com/problem/content/1194/
// 1192. 奖金

#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = 20010;

struct Edge {
    int to, next;
} edges[M];
int head[N], idx = -1;
int d[N];
int dist[N];
int n, m;
vector<int> topo;

bool topsort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int j = edges[i].to;
            if (--d[j] == 0) q.push(j);
        }
    }
    return topo.size() == n;
}

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(v, u);
        d[u]++;
    }

    if (!topsort()) {
        cout << "Poor Xed" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) dist[i] = 100;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int u = topo[i - 1];
        for (int j = head[u]; j != -1; j = edges[j].next) {
            int v = edges[j].to;
            dist[v] = max(dist[v], dist[u] + 1);
        }
        res += dist[u];
    }

    cout << res << endl;

    return 0;
}