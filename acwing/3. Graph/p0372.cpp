// https://www.acwing.com/problem/content/374/

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

bool g[N][N], vis[N][N];

pair<int, int> match[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

bool find(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (vis[nx][ny] || g[nx][ny]) continue;
        auto t = match[nx][ny];
        vis[nx][ny] = true;
        if (t.first == 0 || find(t.first, t.second)) {
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
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!g[i][j] && (i + j) % 2 == 0) {
                memset(vis, 0, sizeof vis);
                if (find(i, j)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
