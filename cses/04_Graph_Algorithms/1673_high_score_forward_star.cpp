// https://cses.fi/problemset/task/1673
// High Score - Forward Star Implementation

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2510 ;
const int MAXM = 5005 ;

struct Edge {
    int to;
    ll weight;
    int next;
} edges[MAXM];

int head[MAXN], cnt = 1;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;

        edges[cnt] = {b, x, head[a]};
        head[a] = cnt++;
    }
    
    vector<ll> dist(n + 1, LLONG_MIN);
    dist[1] = 0;
    
    
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist[u] == LLONG_MIN) continue;
            for (int e = head[u]; e != 0; e = edges[e].next) {
                int v = edges[e].to;
                ll w = edges[e].weight;
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    
    vector<bool> has_pos_cycle(n + 1, false);
    for (int u = 1; u <= n; u++) {
        if (dist[u] == LLONG_MIN) continue;
        for (int e = head[u]; e != 0; e = edges[e].next) {
            int v = edges[e].to;
            ll w = edges[e].weight;
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                has_pos_cycle[v] = true;
            }
        }
    }
    
    // Propagate positive cycle flag
    for (int i = 0; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (has_pos_cycle[u]) {
                for (int e = head[u]; e != 0; e = edges[e].next) {
                    has_pos_cycle[edges[e].to] = true;
                }
            }
        }
    }
    
    if (has_pos_cycle[n]) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }
    
    return 0;
}
