// https://www.acwing.com/problem/content/380/
// Knight placement on chessboard - bipartite matching
// Color cells like chessboard, knights attack opposite color
// Maximum knights = n*n - maximum matching

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int g[N][N];
pair<int, int> match[N][N];
bool vis[N][N];

int n, m;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool find(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (vis[nx][ny] || g[nx][ny]) continue;
        vis[nx][ny] = true;
        if (match[nx][ny] == make_pair(0, 0) || find(match[nx][ny].first, match[nx][ny].second)) {
            match[nx][ny] = {x, y};
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!g[i][j] && (i + j) % 2 == 0) {
                memset(vis, 0, sizeof vis);
                if (find(i, j)) {
                    ans++;
                }
            }
        }
    }

    cout << n * m - t - ans << "\n";
    return 0;
}