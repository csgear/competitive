// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int dp[MAXN][MAXN];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1,        // Delete from s1
                                dp[i][j - 1] + 1,        // Insert into s1
                                dp[i - 1][j - 1] + 1});  // Replace in s1
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}