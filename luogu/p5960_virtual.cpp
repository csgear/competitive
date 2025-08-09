// https://www.luogu.com.cn/problem/P5960
// 差分约束 (Difference Constraints) using SPFA with Virtual Source

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt;
    int w;
} edge[MAXN * 2];

int head[MAXN], cnt = 1;
int dist[MAXN], times[MAXN];
bool in_queue[MAXN];

void add_edge(int u, int v, int w) {
    edge[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

// SPFA algorithm: returns true if negative cycle detected, false otherwise
bool spfa(int n, int start) {
    // Initialize distances
    fill(dist, dist + n + 1, INF);
    fill(times, times + n + 1, 0);
    fill(in_queue, in_queue + n + 1, false);

    queue<int> q;
    dist[start] = 0;
    q.push(start);
    in_queue[start] = true;
    times[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            int w = edge[i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    times[v]++;

                    if (times[v] > n + 1) {  // n+1 because we have virtual node 0
                        return true;         // Negative cycle detected
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // For constraint xa - xb <= c, add edge b -> a with weight c
        add_edge(b, a, c);
    }

    for (int i = 1; i <= n; i++) {
        add_edge(0, i, 0);
    }

    if (spfa(n, 0)) {
        cout << "NO\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << dist[i];
            if (i < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
