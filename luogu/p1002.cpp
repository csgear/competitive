// https://www.luogu.com.cn/problem/P1002

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 25;
int vis[N][N] = {};
long long dp[N][N];

int dir[9][2] = {0, 0, -1, 2, 2, -1, 1, -2, -2, 1, -2, -1, -1, -2, 2, 1, 1, 2};

int n, m, x, y;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y;

    for (int i = 0; i < 9; i++) {
        int tx = x + dir[i][0], ty = y + dir[i][1];
        if (0 <= tx && tx <= n && 0 <= ty && ty <= m) {
            vis[tx][ty] = 1;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (vis[i][j]) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}