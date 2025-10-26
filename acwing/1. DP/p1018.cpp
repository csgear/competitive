// https://www.acwing.com/problem/content/1020/
// Grid DP - maximum sum path with restricted moves
// State: f[i][j] = max sum reaching (i, j)
// Movements depend on problem constraints (typically right/down)

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int a[N][N];
int f[N][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    memset(f, 0x3f, sizeof f);

    f[1][1] = a[1][1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + a[i][j]);
        }
    }
    cout << f[n][n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}