#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C, M;
    cin >> R >> C >> M;

    // compute the value on fly instead of using 2d grid
    // vector<vector<int>> grid(R, vector<int>(C, 0));

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         grid[i][j] = (i * C + j) % M + 1;
    //     }
    // }

    vector<int> dp(C, 0);

    for (int j = 0; j < C; j++) {
        dp[j] = (0 * C + j) % M + 1;
    }

    for (int i = 1; i < R; i++) {
        vector<int> new_dp(C, INT_MAX);
        for (int j = 0; j < C; j++) {
            for (int dj = -1; dj <= 1; dj++) {
                int col = j + dj;
                int val = ((i * C) + j) % M + 1;
                if (col >= 0 && col < C) {
                    new_dp[j] = min(new_dp[j], val + dp[col]);
                }
            }
        }
        dp = new_dp;
    }

    int res = INT_MAX;
    for (int j = 0; j < C; j++) {
        res = min(res, dp[j]);
    }

    cout << res << endl;

    return 0;
}