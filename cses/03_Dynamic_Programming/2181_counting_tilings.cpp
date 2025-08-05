// https://cses.fi/problemset/task/2181

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<long long>> dp;

// Generate all valid next states from current mask
void generate(int pos, int current_mask, int next_mask, vector<int>& next_states) {
    if (pos == n) {
        next_states.push_back(next_mask);
        return;
    }

    if (current_mask & (1 << pos)) {
        // Current position is filled, move to next
        generate(pos + 1, current_mask, next_mask, next_states);
    } else {
        // Current position is empty, we have two choices:

        // 1. Place vertical tile (1x2): fills current and next position
        if (pos + 1 < n && !(current_mask & (1 << (pos + 1)))) {
            generate(pos + 2, current_mask | (1 << pos) | (1 << (pos + 1)), next_mask, next_states);
        }

        // 2. Place horizontal tile (2x1): fills current position,
        //    and corresponding position in next column
        generate(pos + 1, current_mask | (1 << pos), next_mask | (1 << pos), next_states);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // dp[col][mask] = number of ways to tile up to column 'col'
    // where 'mask' represents which cells extend into next column
    dp.assign(m + 1, vector<long long>(1 << n, 0));

    // Base case: no columns processed, no extensions
    dp[0][0] = 1;

    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[col][mask] == 0) continue;

            vector<int> next_states;
            generate(0, mask, 0, next_states);

            for (int next_mask : next_states) {
                dp[col + 1][next_mask] = (dp[col + 1][next_mask] + dp[col][mask]) % MOD;
            }
        }
    }

    cout << dp[m][0] << '\n';
    return 0;
}
