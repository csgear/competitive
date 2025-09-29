// https://cses.fi/problemset/task/2229

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;

int n, k;

int main() {
    cin >> n >> k;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<int> new_dp(k + 1, 0);
        for (int j = 0; j <= k; ++j) {
            new_dp[j] = (new_dp[j] + dp[j]) % MOD;
            if (j > 0) {
                new_dp[j] = (new_dp[j] + new_dp[j - 1]) % MOD;
            }
            if (j - i >= 0) {
                new_dp[j] = (new_dp[j] - dp[j - i] + MOD) % MOD;
            }
        }
        dp = new_dp;
    }
    cout << dp[k] << endl;
    return 0;
}