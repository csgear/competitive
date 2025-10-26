// https://www.acwing.com/problem/content/277/
// Pass the coin - optimized version with 3D DP
// Two people walk simultaneously, simplified state representation
// f[k][i][j] instead of 4D, using diagonal property (k = i+j)

#include <bits/stdc++.h>
using namespace std;

const int N = 55, INF = 0x3f3f3f3f;

int m, n;
int g[N][N];
int f[N * 2][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for (int k = 1; k <= m + n; k++) {
        for (int x1 = 1; x1 <= m; x1++) {
            for (int x2 = 1; x2 <= m; x2++) {
                int y1 = k - x1;
                int y2 = k - x2;
                if (y1 < 1 || y1 > n || y2 < 1 || y2 > n) continue;
                if (x1 != x2 || k == 2 || k == n + m) {
                    int val = g[x1][y1] + g[x2][y2];
                    f[k][x1][x2] = max({f[k - 1][x1 - 1][x2 - 1], f[k - 1][x1 - 1][x2],
                                        f[k - 1][x1][x2 - 1], f[k - 1][x1][x2]}) +
                                   val;
                }
            }
        }
    }
    cout << f[m + n][m][m] << endl;
    return 0;
}