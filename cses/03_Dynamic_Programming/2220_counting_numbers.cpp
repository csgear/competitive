// https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXLEN = 19;
ll dp[MAXLEN][10][2];

ll f(ll num, ll offset, int len, int pre, int tight) {
    if (len == 0) return 1;  // Base case: successfully built a valid number

    // Only memoize when pre >= 0 (valid array index)
    if (pre >= 0 && dp[len - 1][pre][tight] != -1) {
        return dp[len - 1][pre][tight];
    }

    int cur = (num / offset) % 10;  // Current digit in the target number
    int limit = tight ? cur : 9;    // Upper limit for current position
    ll ans = 0;

    for (int i = 0; i <= limit; i++) {
        if (pre == -1) {
            // First digit state - handle leading zeros and first non-zero digit
            if (i == 0) {
                // Leading zero: stay in "first digit" state (pre = -1)
                ans += f(num, offset / 10, len - 1, -1, tight && (i == limit));
            } else {
                // First non-zero digit: transition to normal state (pre = i)
                ans += f(num, offset / 10, len - 1, i, tight && (i == limit));
            }
        } else if (i != pre) {
            // Normal state: check adjacency constraint (adjacent digits must differ)
            ans += f(num, offset / 10, len - 1, i, tight && (i == limit));
        }
        // Note: if i == pre, we skip this digit (violates adjacency constraint)
    }

    // Only memoize valid states (when pre >= 0)
    if (pre >= 0) dp[len - 1][pre][tight] = ans;
    return ans;
}

ll count(ll num) {
    if (num == 0) return 1;  // Special case: zero is a valid single-digit number

    // Calculate number length and initial offset for positional extraction
    int len = 1;
    ll offset = 1, tmp = num / 10;
    while (tmp > 0) {
        len++;
        offset *= 10;
        tmp /= 10;
    }

    // Initialize DP table with -1 (uncomputed state)
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    // Start parameters explanation:
    // num = target number, offset = positional value, len = remaining digits
    // pre = -1: No previous digit yet (sentinel for "first digit" state)
    // tight = 1: Initially constrained by upper bound (must stay ≤ num)
    return f(num, offset, len, -1, 1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << endl;
    return 0;
}