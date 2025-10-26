// https://www.acwing.com/problem/content/1029/
// Two paths from top-left to bottom-right simultaneously
// 3D DP: f[k][i][j] = max sum with two people at (i, k-i) and (j, k-j)
// Both paths collect items, avoid double counting same cell

#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int g[N][N];
int f[2 * N][N][N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        g[a][b] = c;
    }

    for (int k = 1; k <= 2 * n; k++) {
        for (int x1 = 1; x1 <= n; x1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                int y1 = k - x1;
                int y2 = k - x2;
                if (y1 < 1 || y1 > n || y2 < 1 || y2 > n) continue;
                int val = g[x1][y1];
                if (x1 != x2) val += g[x2][y2];
                f[k][x1][x2] = max({f[k - 1][x1 - 1][x2 - 1], f[k - 1][x1 - 1][x2],
                                    f[k - 1][x1][x2 - 1], f[k - 1][x1][x2]}) +
                               val;
            }
        }
    }

    cout << f[2 * n][n][n] << "\n";

    return 0;
}