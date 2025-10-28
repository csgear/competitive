// https://www.acwing.com/problem/content/342/
// Binary search + 0-1 BFS on edge weight threshold
// For each threshold, check if path exists with ≤ K edges exceeding threshold
// Uses deque: push_front for 0-weight, push_back for 1-weight edges

#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 10010 * 2 + 10;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt = -1;
int dist[N];
int n, m, K;

void add_edge(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool check(int limit) {
    memset(dist, 0x3f, sizeof dist);
    deque<int> q;
    dist[1] = 0;
    q.push_back(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int v = edges[i].to;
            int cost = (edges[i].w > limit) ? 1 : 0;
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                if (cost == 0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    return dist[n] <= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof head);

    cin >> n >> m >> K;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    int l = 0, r = 1e6 + 1, ans = -1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (ans > 1e6) ans = -1;
    cout << ans << "\n";

    return 0;
}