// https://www.acwing.com/problem/content/1059/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 110;

// 0 not holding stock, 1 holding stock
// int f[N][M][2];
int dp[M][2];

int n, m, w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    // memset(f, -0x3f, sizeof(f));
    memset(dp, -0x3f, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        // f[i][0][0] = 0;
        dp[0][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= m; j++) {
        for (int j = m; j >= 1; j--) {
            dp[j][0] = max(dp[j][0], dp[j][1] + w[i]);
            dp[j][1] = max(dp[j][1], dp[j - 1][0] - w[i]);
            // f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            // f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }
    }

    int ans = 0;

    // for (int i = 0; i <= k; i++) ans = max(ans, f[n][i][0]);
    for (int i = 0; i <= m; i++) ans = max(ans, dp[i][0]);

    cout << ans << endl;

    return 0;
}