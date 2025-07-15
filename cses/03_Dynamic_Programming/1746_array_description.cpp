// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int MAXM = 105;
const int MOD = 1000000007;
int dp[MAXN][MAXM];
int ans = 0;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int prev = max(1, j - 1); prev <= min(m, j + 1); prev++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
                }
            }
        } else {
            int j = a[i];
            for (int prev = max(1, j - 1); prev <= min(m, j + 1); prev++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans << endl;
    return 0;
}