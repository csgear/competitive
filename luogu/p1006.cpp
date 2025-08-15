// https://www.luogu.com.cn/problem/P1006

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55, inf = 0x3f3f3f3f;

int f[MAXN][MAXN][MAXN][MAXN], a[MAXN][MAXN];
int m, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                for (int l = 1; l <= n; l++) {
                    // down + down, down + right, right + down, right + right
                    f[i][j][k][l] = max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]);
                    f[i][j][k][l] =
                        max(f[i][j][k][l], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]));
                    f[i][j][k][l] += a[i][j] + a[k][l];

                    if (i == k && j == l && !((i == 1 && j == 1) || (i == m && j == n))) {
                        f[i][j][k][l] = -inf;
                    }
                    ans = max(ans, f[i][j][k][l]);
                }
            }
        }
    }
    cout << f[m][n][m][n] << endl;
    return 0;
}