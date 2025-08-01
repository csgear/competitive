// https://atcoder.jp/contests/abc416/tasks/abc416_e

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 510;
const ll INF = 1e18;

int N, M, K, Q, T;
ll dist[MAXN][MAXN];
ll ans = 0;

void addEdge(int x, int y, ll cost) {
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) {
            ll tmp = min(dist[i][x] + dist[y][j], dist[i][y] + dist[x][j]) + cost;
            if (tmp != INF && dist[i][j] > tmp) {
                // we want both i and j are real cities
                if (i != N + 1 && j != N + 1) {
                    if (dist[i][j] != INF) {
                        ans -= dist[i][j];
                    }
                    ans += tmp;
                }
                dist[i][j] = tmp;
            }
        }
    }
}

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

    // Initialize distances
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
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
        dist[d][N + 1] = min(dist[d][N + 1], 1LL * T);
        dist[N + 1][d] = min(dist[N + 1][d], 1LL * T);
    }

    floyd_warshall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] < INF) {
                ans += dist[i][j];
            }
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            // Add new road (double the cost)
            int x, y, t;
            cin >> x >> y >> t;
            ll cost = 2LL * t;
            addEdge(x, y, cost);
        } else if (type == 2) {
            // Add new airport
            int x;
            cin >> x;
            addEdge(x, N + 1, T);
        } else if (type == 3) {
            cout << (ans / 2) << "\n";
        }
    }

    return 0;
}