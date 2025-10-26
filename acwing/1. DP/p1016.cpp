// https://www.acwing.com/problem/content/1018/
// Longest Decreasing Subsequence variant
// DP to find longest strictly decreasing subsequence
// State: dp[i] = length of LDS ending at i

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;

int dp[N];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}