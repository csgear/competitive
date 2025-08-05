// https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i];
        total += a[i];
    }

    // dp[i] represents the maximum score difference (Player 1 - Player 2)
    // for the current interval length being processed

    // State Transition Explanation:
    // dp[l] = max(a[l] - dp[l+1], a[r] - dp[l])
    //
    // When Player 1 faces interval [l, r], they have two choices:
    //
    // Choice 1: Take a[l] (leftmost element)
    //   - Player 1 gets +a[l] points
    //   - Remaining interval is [l+1, r] where Player 2 plays first
    //   - On [l+1, r], Player 2 will achieve optimal score difference of +dp[l+1]
    //   - So Player 1's net advantage = a[l] - dp[l+1]
    //
    // Choice 2: Take a[r] (rightmost element)
    //   - Player 1 gets +a[r] points
    //   - Remaining interval is [l, r-1] where Player 2 plays first
    //   - On [l, r-1], Player 2 will achieve optimal score difference of +dp[l]
    //   - So Player 1's net advantage = a[r] - dp[l]
    //
    // Player 1 chooses whichever gives maximum advantage

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            dp[l] = max(a[l] - dp[l + 1], a[r] - dp[l]);
        }
    }

    cout << (total + dp[0]) / 2 << endl;

    return 0;
}