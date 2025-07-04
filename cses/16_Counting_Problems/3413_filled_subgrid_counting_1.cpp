// https://cses.fi/problemset/task/3413

#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
char a[N][N];
int dp[N][N];
int n, k;

long long solve(int c) {
    memset(dp, 0, sizeof(dp));
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 'A' + c) {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                ans += dp[i][j];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans = solve(i);
        cout << ans << endl;
    }
    return 0;
}