// https://cses.fi/problemset/task/3359

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<string>> dp(n, vector<string>(n));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            string from_up = dp[i - 1][j] + grid[i][j];
            string from_left = dp[i][j - 1] + grid[i][j];

            dp[i][j] = min(from_up, from_left);
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
    return 0;
}