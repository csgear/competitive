// https://www.luogu.com.cn/problem/P1004

#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int dp[N][N][N][N];
int a[N][N];
int n, x, y, z;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (;;) {
        cin >> x >> y >> z;
        if (x == y && y == z && z == 0) {
            break;
        } else {
            a[x][y] = z;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    int value;
                    if (i == k && l == j) {
                        value = a[i][j];
                    } else {
                        value = a[i][j] + a[k][l];
                    }
                    dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]),
                                         max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) +
                                     value;
                }
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
    return 0;
}
