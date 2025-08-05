// https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;

// dp[i][0]: Number of ways to fill first i rows ending with one merged 2×1 block
// dp[i][1]: Number of ways to fill first i rows ending with two separate 1×1 blocks
ll dp[MAXN][2];

void precompute() {
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }
}

int solve(int n) { return (dp[n][0] + dp[n][1]) % MOD; }
int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}