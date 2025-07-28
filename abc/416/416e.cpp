// https://atcoder.jp/contests/abc416/tasks/abc416_e

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 510;
const ll INF = 1e18;

int N, M, K, Q, T;
ll dist[MAXN][MAXN];
bool has_airport[MAXN];
int v;

void floyd_warshall() {
    for (int k = 1; k <= N + 1; k++) {
        for (int i = 1; i <= N + 1; i++) {
            for (int j = 1; j <= N + 1; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v = N + 1;

    // Initialize distances
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
        has_airport[i] = false;
    }

    // Initial roads (double the cost)
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ll cost = 2LL * c;
        dist[a][b] = min(dist[a][b], cost);
        dist[b][a] = min(dist[b][a], cost);
    }

    cin >> K >> T;

    // Initial airports
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        has_airport[d] = true;
    }

    // Connect airports to virtual node (use T instead of T/2)
    for (int i = 1; i <= N; i++) {
        if (has_airport[i]) {
            dist[i][v] = min(dist[i][v], 1LL * T);
            dist[v][i] = min(dist[v][i], 1LL * T);
        }
    }

    // Initial computation
    floyd_warshall();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            // Add new road (double the cost)
            int x, y, t;
            cin >> x >> y >> t;
            ll cost = 2LL * t;

            if (cost < dist[x][y]) {
                dist[x][y] = cost;
                dist[y][x] = cost;
                // Only update affected pairs
                for (int u = 1; u <= N + 1; ++u) {
                    for (int w = 1; w <= N + 1; ++w) {
                        if (dist[u][x] < INF && dist[y][w] < INF)
                            dist[u][w] = min(dist[u][w], dist[u][x] + cost + dist[y][w]);
                        if (dist[u][y] < INF && dist[x][w] < INF)
                            dist[u][w] = min(dist[u][w], dist[u][y] + cost + dist[x][w]);
                    }
                }
            }
        } else if (type == 2) {
            // Add new airport
            int x;
            cin >> x;

            if (!has_airport[x]) {
                has_airport[x] = true;
                dist[x][v] = min(dist[x][v], 1LL * T);
                dist[v][x] = min(dist[v][x], 1LL * T);
                // Update all pairs via the virtual node
                for (int i = 1; i <= N + 1; ++i) {
                    for (int j = 1; j <= N + 1; ++j) {
                        if (dist[i][v] < INF && dist[v][j] < INF) {
                            dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
                        }
                    }
                }
            }
        } else if (type == 3) {
            // Calculate sum of all shortest paths (ignore virtual node)
            ll sum = 0;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][j] < INF) {
                        sum += dist[i][j];
                    }
                }
            }
            cout << (sum / 2) << "\n";
        }
    }

    return 0;
}