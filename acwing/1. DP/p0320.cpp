// https://www.acwing.com/problem/content/322/
// Energy necklace - circular arrangement optimization
// Break circle, use interval DP to find max energy release
// State: dp[i][j] = max energy for beads in range [i, j]

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 110, M = N << 1;

const int INF = 0x3f3f3f3f;

int a[M];
LL f[M][M];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    memset(f, -0x3f, sizeof f);

    for (int i = 1; i <= (n << 1); i++) {
        f[i][i + 1] = 0;
    }

    for (int len = 3; len <= n + 1; len++) {
        for (int l = 1; l + len - 1 <= (n << 1); l++) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++) {
                LL val = f[l][k] + f[k][r] + (LL)a[l] * a[k] * a[r];
                f[l][r] = max(f[l][r], val);
            }
        }
    }

    LL ans = 0;
    for (int l = 1; l <= n; ++l) {
        ans = max(ans, f[l][l + n]);
    }
    cout << ans << endl;
    return 0;
}