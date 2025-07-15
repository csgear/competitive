// https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // dp[mask] = {rides, last_weight}
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});

    // dp[0] = {1, 0};
    // for (int mask = 0; mask < (1 << n); mask++) {
    //     for (int i = 0; i < n; i++) {
    //         if (!(mask & (1 << i))) {
    //             auto [rides, last] = dp[mask];
    //             if (last + w[i] <= x) {
    //                 // Add i to current ride
    //                 auto better = make_pair(rides, last + w[i]);
    //                 if (better < dp[mask | (1 << i)]) {
    //                     dp[mask | (1 << i)] = better;
    //                 }
    //             } else {
    //                 // New ride for i
    //                 auto better = make_pair(rides + 1, w[i]);
    //                 if (better < dp[mask | (1 << i)]) {
    //                     dp[mask | (1 << i)] = better;
    //                 }
    //             }
    //         }
    //     }
    // }

    // cout << dp[(1 << n) - 1].first << endl;

    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); ++mask) {
        // find the best way to reach this mask
        dp[mask] = {n + 1, 0};
        for (int p = 0; p < n; ++p) {
            if (mask & (1 << p)) {
                auto [rides, last] = dp[mask ^ (1 << p)];
                pair<int, int> added;
                if (last + w[p] <= x) {
                    added = {rides, last + w[p]};
                } else {
                    added = {rides + 1, w[p]};
                }
                dp[mask] = min(dp[mask], added);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}