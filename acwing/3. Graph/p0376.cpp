// https://www.acwing.com/problem/content/378/
// Bipartite matching - maximum independent set
// Left side: items, Right side: constraints
// Answer = total items - maximum matching

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int K = 2010;

struct Edge {
    int to, next;
} edges[K];

int head[N], cnt;
bool vis[N];
int match[N];

int n, m, k;

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

bool find(int u) {
    for (int i = head[u]; i != 0; i = edges[i].next) {
        int v = edges[i].to;
        if (vis[v]) continue;
        vis[v] = true;
        if (match[v] == -1 || find(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n, n) {
        cin >> m >> k;
        memset(head, 0, sizeof(head));
        memset(match, -1, sizeof(match));
        cnt = 1;
        for (int i = 0; i < k; i++) {
            int t, u, v;
            cin >> t >> u >> v;
            if (u != 0 && v != 0) {
                add_edge(u, v);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            if (find(i)) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
