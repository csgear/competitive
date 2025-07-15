// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int dp[MAXN];

int main() {
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            temp /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}