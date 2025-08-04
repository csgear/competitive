// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int target = sum / 2;

    // Space-optimized 0-1 knapsack DP using 1D array
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << dp[target] << endl;
    return 0;
}