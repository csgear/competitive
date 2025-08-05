// https://cses.fi/problemset/task/2220
// Alternative solution using 4D DP array with explicit started flag

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXLEN = 19;
ll dp[MAXLEN][10][2][2];  // [pos][last_digit][tight][started]

// pos: Current position in the number (0 = leftmost digit)
// last: Previous digit placed (used for adjacency constraint checking)
// tight: Whether we're constrained by upper bound (1 = must stay ≤ original number)
// started: Whether we've placed the first non-zero digit (0 = still in leading zeros)
ll solve(string &s, int pos, int last, int tight, int started) {
    if (pos == s.length()) {
        return started;  // Only count if we've placed at least one non-zero digit
    }

    if (dp[pos][last][tight][started] != -1) {
        return dp[pos][last][tight][started];
    }

    int limit = tight ? (s[pos] - '0') : 9;
    ll ans = 0;

    for (int digit = 0; digit <= limit; digit++) {
        int new_tight = tight && (digit == limit);
        int new_started = started || (digit > 0);

        if (started && digit == last) {
            // Skip if same as previous digit (violates constraint)
            continue;
        }

        ans += solve(s, pos + 1, digit, new_tight, new_started);
    }

    return dp[pos][last][tight][started] = ans;
}

ll count(ll num) {
    if (num <= 0) return 0;

    string s = to_string(num);

    // Initialize DP
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < 10; j++) {
            for (int t = 0; t < 2; t++) {
                for (int st = 0; st < 2; st++) {
                    dp[i][j][t][st] = -1;
                }
            }
        }
    }

    // Start parameters explanation:
    // pos = 0: Begin at the first (leftmost) digit position
    // last = 0: Initial last digit is 0 (arbitrary since started=0)
    // tight = 1: We must respect the upper bound constraint initially
    // started = 0: We haven't placed any non-zero digit yet
    return solve(s, 0, 0, 1, 0);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << endl;
    return 0;
}
