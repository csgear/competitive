// https://www.acwing.com/problem/content/274/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;

int dp[N][N];
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        int maxv = 0;
        for (int j = 1; j <= n; j++) {
            if (b[j] < a[i]) maxv = max(maxv, dp[i - 1][j]);
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], maxv + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            }
        }
    }
    cout << *max_element(dp[n] + 1, dp[n] + n + 1) << "\n";

    return 0;
}
