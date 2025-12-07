// https://www.acwing.com/problem/content/378/
// Bipartite graph: left = A's modes (1~n-1), right = B's modes (1~m-1)
// Each task (a,b) with a!=0 and b!=0 is an edge.
// Minimum machine restarts = size of minimum vertex cover = maximum matching.

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int K = 2010;

struct Edge {
    int to, next;
} edges[K];

int head[N], idx = -1;
bool vis[N];
int match[N];

int n, m, k;

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

bool find(int u) {
    for (int i = head[u]; i != -1; i = edges[i].next) {
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
        memset(head, -1, sizeof(head));
        idx = -1;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < k; i++) {
            int t, u, v;
            cin >> t >> u >> v;
            if (u != 0 && v != 0) {
                add_edge(u, v);
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            if (find(i)) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
