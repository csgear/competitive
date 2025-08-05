// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        total += coins[i];
    }

    // Space-optimized knapsack problem
    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = total; j >= coins[i]; j--) {
            dp[j] = dp[j] || dp[j - coins[i]];
        }
    }

    // Count distinct sums
    int count = 0;
    for (int i = 1; i <= total; i++) {
        if (dp[i]) {
            count++;
        }
    }

    cout << count << '\n';
    for (int i = 1; i <= total; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}