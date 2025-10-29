// https://www.luogu.com.cn/problem/P5340

#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
const int M = 200010;
const int K = 30;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt = -1;

int a[N], d[N][K], st[N][K];

void add_edge(int u, int v, int w) {
    edges[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

int n, m, k, S, T;

int spfa() {
    memset(d, 0x3f, sizeof d);
    memset(st, 0, sizeof st);

    int diff = a[S] == 1 ? 1 : -1;
    if (abs(diff) > k) return -1;

    queue<pair<int, int>> q;
    q.push({S, diff});
    d[S][diff + k] = 0;
    st[S][diff + k] = true;

    while (!q.empty()) {
        auto [u, diff] = q.front();
        q.pop();

        int idx = diff + k;
        st[u][idx] = false;

        for (int i = head[u]; i != -1; i = edges[i].nxt) {
            int to = edges[i].to;
            int w = edges[i].w;
            int new_diff = diff + (a[to] == 1 ? 1 : -1);

            if (abs(new_diff) > k) continue;
            int v_idx = new_diff + k;

            if (d[to][v_idx] > d[u][idx] + w) {
                d[to][v_idx] = d[u][idx] + w;
                if (!st[to][v_idx]) {
                    st[to][v_idx] = true;
                    q.push({to, new_diff});
                }
            }
        }
    }

    int res = *min_element(d[T], d[T] + 2 * k + 1);
    return res == INF ? -1 : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        cnt = -1;
        memset(head, -1, sizeof head);
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        cin >> S >> T;

        cout << spfa() << endl;
    }

    return 0;
}