// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1005;
int dp[MAXN][MAXN];

vector<string> grid;

int d[][2] = {{1, 0}, {0, 1}};

int main() {
    int n;
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                // handle corner case when grid[0][0] is '*'
                dp[i][j] = 0;
            }
            for (auto& dir : d) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni < n && nj < n && grid[ni][nj] == '.') {
                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}