// https://www.acwing.com/problem/content/1070/

#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int M = N << 1;
const int INF = 0x3f3f3f3f;

int a[M], pre[M];
int f[M][M], g[M][M];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= (n << 1); i++) pre[i] = pre[i - 1] + a[i];

    // f for max, g for min
    memset(f, -0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);

    for (int i = 1; i <= (n << 1); i++) {
        f[i][i] = g[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        // l + len - 1 is the boundary of r
        for (int l = 1; l + len - 1 <= (n << 1); l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1]);
                g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }

    int minv = INF, maxv = -INF;
    for (int l = 1; l <= n; ++l) {
        maxv = max(maxv, f[l][l + n - 1]);
        minv = min(minv, g[l][l + n - 1]);
    }

    cout << minv << endl << maxv << endl;

    return 0;
}
