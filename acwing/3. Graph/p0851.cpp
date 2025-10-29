// https://www.acwing.com/problem/content/853/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m;

struct Edge {
    int to, next, w;
} edges[M];

int head[N], cnt = -1;

int d[N];
bool st[N];

void add(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

int spfa(int s, int t) {
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    st[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int w = edges[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }

    return d[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    int res = spfa(1, n);

    if (res == 0x3f3f3f3f)
        cout << "impossible" << endl;
    else
        cout << res << endl;

    return 0;
}