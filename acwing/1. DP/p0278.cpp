// https://www.acwing.com/problem/content/280/

#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
const int M = 10000 + 5;

int a[N];
int dp[M];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[m] << endl;

    return 0;
}