// https://www.acwing.com/problem/content/1023/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 20;
const int M = 3000 + 5;
int a[N];
LL dp[M];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= m; j++) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}