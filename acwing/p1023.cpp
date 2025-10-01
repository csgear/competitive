// https://www.acwing.com/problem/content/1025/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int dp[N];
int v[] = {0, 10, 20, 50, 100};

int main() {
    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= 4; i++) {
        for (int j = v[i]; j <= n; j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[n] << endl;

    return 0;
}