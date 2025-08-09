// https://cses.fi/problemset/task/1729
// Stick Game - Simple DP Solution (Faster)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> moves(k);
    for (int i = 0; i < k; i++) {
        cin >> moves[i];
    }

    vector<bool> dp(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int move : moves) {
            if (i >= move && !dp[i - move]) {
                dp[i] = true;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << '\n';

    return 0;
}
