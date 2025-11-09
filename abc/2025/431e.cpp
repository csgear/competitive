// https://atcoder.jp/contests/abc431/tasks/abc431_e
// E - Reflection on Grid

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        auto get_id = [&](int i, int j) { return i * m + j; };

        vector<vector<int>> dist(n * m, vector<int>(4, INF));
        vector<vector<bool>> vis(n * m, vector<bool>(4, false));
        deque<tuple<int, int, int>> dq;

        dist[0][0] = 0;
        dq.push_back({0, 0, 0});

        int ans = INF;

        while (!dq.empty()) {
            auto [i, j, d] = dq.front();
            dq.pop_front();
            int u = get_id(i, j);
            if (vis[u][d]) continue;
            vis[u][d] = true;

            // Try placing mirror type A(0), B(1), C(2) -> but we use t=1,2,3 for A,B,C
            for (int t = 1; t <= 3; t++) {
                int nd = d;
                if (t == 2) {
                    nd = d ^ 1;  // B = '\'
                } else if (t == 3) {
                    nd = d ^ 3;  // C = '/'
                }

                int ni = i + dx[nd];
                int nj = j + dy[nd];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    if (i == n - 1 && j == m - 1 && nd == 0) {
                        int cost = (grid[i][j] != 'A' + t - 1);
                        ans = min(ans, dist[u][d] + cost);
                    }
                    continue;
                }

                int v = get_id(ni, nj);
                int cost = (grid[i][j] != 'A' + t - 1);
                if (dist[u][d] + cost < dist[v][nd]) {
                    dist[v][nd] = dist[u][d] + cost;
                    if (cost == 0) {
                        dq.push_front({ni, nj, nd});
                    } else {
                        dq.push_back({ni, nj, nd});
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
