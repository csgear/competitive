// https://cses.fi/problemset/task/1080

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 505;
const int MOD = 1e9 + 7;
char s[N];
LL dp[N][N];
LL C[N][N];
int n;

void precompute_binomial() {
    for (int i = 0; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute_binomial();

    scanf("%s", s + 1);
    n = strlen(s + 1);

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        dp[i + 1][i] = 1;
    }

    for (int len = 2; len <= n; len += 2) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;

            for (int k = i + 1; k <= j; k += 2) {
                if (s[i] == s[k]) {
                    LL left = dp[i + 1][k - 1];
                    LL right = dp[k + 1][j];

                    int total_pairs = (j - i + 1) / 2;
                    int left_pairs = (k - i + 1) / 2;

                    if (left_pairs >= 0 && left_pairs <= total_pairs) {
                        LL ways = (left * right) % MOD;
                        ways = (ways * C[total_pairs][left_pairs]) % MOD;
                        dp[i][j] = (dp[i][j] + ways) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}