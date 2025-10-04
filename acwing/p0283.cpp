// https://www.acwing.com/problem/content/285/
// https://www.luogu.com.cn/problem/P4342

#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n;
int a[N];
char op[N];

// f for max, g for min
int f[N][N], g[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> a[i];
        op[i + n] = op[i];
        a[i + n] = a[i];
    }

    memset(f, -0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);

    for (int i = 1; i <= 2 * n; i++) {
        f[i][i] = g[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                if (op[k + 1] == 't') {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r]);
                } else {
                    f[l][r] = max(f[l][r], f[l][k] * f[k + 1][r]);
                    f[l][r] = max(f[l][r], g[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], f[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] * f[k + 1][r]);
                }
            }
        }
    }

    int ans = -INF;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i][i + n - 1]);
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        if (f[i][i + n - 1] == ans) {
            cout << i << " ";
        }
    }

    return 0;
}