// https://cses.fi/problemset/task/1635

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
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - values[j] >= 0) {
                dp[i] = (dp[i] + dp[i - values[j]]) % mod;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}