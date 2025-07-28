// https://atcoder.jp/contests/abc415/tasks/abc415_e

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 505;  // Increased to handle N ≤ 500
const ll INF = 1e18;

int N, M, K, Q, T;
ll dist[MAXN][MAXN];
bool has_airport[MAXN];

void floyd_warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void update_with_airports() {
    // Connect all cities with airports
    for (int i = 1; i <= N; i++) {
        if (has_airport[i]) {
            for (int j = 1; j <= N; j++) {
                if (i != j && has_airport[j]) {
                    dist[i][j] = min(dist[i][j], (ll)T);
                }
            }
        }
    }

    // Run Floyd-Warshall to update all paths
    floyd_warshall();
}

ll calculate_total_distance() {
    ll total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] < INF) {
                total += dist[i][j];
            }
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> Q >> T;

    // Initialize distances
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Initial roads
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
        dist[b][a] = min(dist[b][a], (ll)c);
    }

    // Initial airports
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        has_airport[d] = true;
    }

    // Initial computation of all shortest paths
    floyd_warshall();
    update_with_airports();

    // Process queries
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            // New road
            int x, y, t;
            cin >> x >> y >> t;

            if (t < dist[x][y]) {
                // Update the direct connection
                dist[x][y] = t;
                dist[y][x] = t;

                // Recompute all shortest paths
                floyd_warshall();
                update_with_airports();
            }
        } else if (type == 2) {
            // New airport
            int x;
            cin >> x;

            if (!has_airport[x]) {
                has_airport[x] = true;

                // Update with the new airport
                update_with_airports();
            }
        } else if (type == 3) {
            // Calculate sum of all shortest paths
            cout << calculate_total_distance() << "\n";
        }
    }

    return 0;
}
