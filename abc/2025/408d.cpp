// https://atcoder.jp/contests/abc408/tasks/abc408_d

#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005];
int sum[200005];

void solve() {
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i - 1] == '1');
    }
    // at most one inteval
    // change all 1s to 0s
    int ans = sum[n];
    // solve in O(n) time using sliding window
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        pre = min(pre, 2 * sum[i - 1] - i);
        ans = min(ans, (sum[n] + 1) + (i - 2 * sum[i] + pre));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}