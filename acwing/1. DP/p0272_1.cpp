// https://www.acwing.com/problem/content/274/
// LCS variant with 1D space optimization
// Uses rolling array or space-compressed DP
// State: optimized to O(n) space instead of O(n²)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;

int a[N], b[N];
int n;

int lcis() {
    vector<int> dp(n + 1, 0);
    int max_len = 0;

    for (int i = 1; i <= n; ++i) {
        int current_max = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i] > b[j]) {
                current_max = max(current_max, dp[j]);
            } else if (a[i] == b[j]) {
                dp[j] = max(dp[j], current_max + 1);
                max_len = max(max_len, dp[j]);
            }
        }
    }
    return max_len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    cout << lcis() << endl;
    return 0;
}