// https://www.acwing.com/problem/content/273/
// Young tableaux counting with 5-dimensional DP
// State: dp[a][b][c][d][e] = count with given row configuration
// Ensures tableau property: rows/columns strictly increasing

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 31;

ll dp[N][N][N][N][N];
int s[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int k;
        cin >> k;
        if (k == 0) break;
        memset(s, 0, sizeof s);
        for (int i = 1; i <= k; i++) cin >> s[i];

        memset(dp, 0, sizeof dp);
        dp[0][0][0][0][0] = 1;
        for (int a = 0; a <= s[1]; a++)
            for (int b = 0; b <= min(a, s[2]); b++)
                for (int c = 0; c <= min(b, s[3]); c++)
                    for (int d = 0; d <= min(c, s[4]); d++)
                        for (int e = 0; e <= min(d, s[5]); e++) {
                            // line a must be longer than line b if add a new element at the end of
                            if (a && a > b) dp[a][b][c][d][e] += dp[a - 1][b][c][d][e];
                            if (b && b > c) dp[a][b][c][d][e] += dp[a][b - 1][c][d][e];
                            if (c && c > d) dp[a][b][c][d][e] += dp[a][b][c - 1][d][e];
                            if (d && d > e) dp[a][b][c][d][e] += dp[a][b][c][d - 1][e];
                            if (e) dp[a][b][c][d][e] += dp[a][b][c][d][e - 1];
                        }
        cout << dp[s[1]][s[2]][s[3]][s[4]][s[5]] << "\n";
    }

    return 0;
}
