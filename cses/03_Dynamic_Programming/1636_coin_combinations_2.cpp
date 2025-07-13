// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    // unbounded knapsack, dp[i] = dp[i - values[j]] + dp[i]
    // process coins in ascending order to avoid double counting
    for (int i = 0; i < n; i++) {
        for (int j = values[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - values[i]]) % mod;
        }
    }

    cout << dp[x] << endl;

    return 0;
}