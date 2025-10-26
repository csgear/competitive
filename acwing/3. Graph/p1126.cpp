// https://www.acwing.com/problem/content/1128/
// Maximum product path - modified Dijkstra
// Use log transformation: log(a*b) = log(a) + log(b)
// Find shortest path in log space, then exponentiate result

#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, m, s, t;
double w[N][N];
double dist[N];
bool st[N];

void dijkstra() {
    dist[s] = 1.0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] < dist[j])) t = j;
        }

        st[t] = true;
        for (int j = 1; j <= n; j++) dist[j] = max(dist[j], dist[t] * w[t][j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        double d = (100.0 - c) / 100;
        w[a][b] = w[b][a] = max(w[a][b], d);
    }

    cin >> s >> t;

    dijkstra();

    cout << fixed << setprecision(8) << 100.0 / dist[t] << endl;

    return 0;
}
