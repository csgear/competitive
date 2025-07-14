// https://cses.fi/problemset/task/3403

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 1005;
int dp[MAXN][MAXM];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    vector<int> result;
    int i = n, j = m;
    while (dp[i][j] > 0) {
        if (a[i] == b[j]) {
            result.push_back(a[i]);
            i--;
            j--;
        } else if (dp[i - 1][j] == dp[i][j]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end());

    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}