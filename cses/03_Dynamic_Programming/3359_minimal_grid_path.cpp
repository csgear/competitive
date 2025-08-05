// https://cses.fi/problemset/task/3359

#include <bits/stdc++.h>
using namespace std;

// Too much spaces
void solve_dp() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<string>> dp(n, vector<string>(n));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            string from_up = dp[i - 1][j] + grid[i][j];
            string from_left = dp[i][j - 1] + grid[i][j];

            dp[i][j] = min(from_up, from_left);
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
}

void solve_queue() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> globalQueue;
    string ans = string(1, grid[0][0]);

    globalQueue.push({0, 0});
    visited[0][0] = 1;

    for (int step = 0; step < 2 * n - 2; step++) {
        char min_char = 'z' + 1;
        queue<pair<int, int>> localQueue;
        while (!globalQueue.empty()) {
            auto [row, col] = globalQueue.front();
            globalQueue.pop();

            // Check both down and right directions
            vector<pair<int, int>> neighbors = {{row + 1, col}, {row, col + 1}};

            for (auto [nr, nc] : neighbors) {
                if (nr < n && nc < n && !visited[nr][nc]) {
                    char next_char = grid[nr][nc];
                    if (next_char < min_char) {
                        min_char = next_char;
                        localQueue = queue<pair<int, int>>();
                    }
                    if (next_char == min_char) {
                        localQueue.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }
        ans += min_char;
        globalQueue = localQueue;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve_queue();

    return 0;
}