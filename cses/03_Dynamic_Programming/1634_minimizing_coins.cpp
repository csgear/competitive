// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<int> dp(x + 1, INF);

    // Base case: 0 coins needed to make 0 sum
    dp[0] = 0;

    // 0-1 knapsack, dp[i] = min(dp[i], dp[i - values[j]] + 1)
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - values[j] >= 0) {
                dp[i] = min(dp[i], dp[i - values[j]] + 1);
            }
        }
    }

    if (dp[x] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}