// https://cses.fi/problemset/task/2088

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Prefix sum for range sum queries
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + x[i];
    }

    // dp[i][j] = minimum cost to split subarray [i, j] into individual elements
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // opt[i][j] = optimal split point for dp[i][j] (Knuth optimization)
    vector<vector<int>> opt(n, vector<int>(n));

    // Initialize opt for length 1 intervals (no splits needed)
    for (int i = 0; i < n; i++) {
        opt[i][i] = i;
    }

    // Fill dp table using interval DP with Knuth optimization
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            // Knuth optimization: opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
            // Handle boundary cases properly
            int start = i;
            int end = j - 1;

            if (j > i + 1) start = max(start, opt[i][j - 1]);
            if (i + 1 < n && j < n) end = min(end, opt[i + 1][j]);

            for (int k = start; k <= end; k++) {
                ll cost = dp[i][k] + dp[k + 1][j] + (pref[j + 1] - pref[i]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    opt[i][j] = k;
                }
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
    return 0;
}
