// https://www.acwing.com/problem/content/1129/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 810;
const int M = 3000;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt, dist[N], cow[N];
bool st[N];

void add_edge(int u, int v, int w) {
    edges[cnt] = {v, head[u], w};
    head[u] = cnt++;
}

void disjakstra(int start) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (st[u]) continue;
        st[u] = true;

        for (int k = head[u]; k != 0; k = edges[k].nxt) {
            int v = edges[k].to, w = edges[k].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, c;
    cin >> n >> p >> c;
    cnt = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cow[x]++;
    }

    for (int i = 1; i <= c; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }

    ll ans = INF;

    for (int i = 1; i <= p; i++) {
        disjakstra(i);
        ll sum = 0;
        bool valid = true;
        for (int j = 1; j <= p; j++) {
            if (dist[j] == INF && cow[j] > 0) {
                valid = false;
                break;
            }
            sum += (ll)dist[j] * cow[j];
        }
        if (valid) ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
