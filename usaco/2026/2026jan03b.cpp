

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N));

    vector<vector<ll>> prefix(N + 1, vector<ll>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix[i][j] = grid[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    const int M = N - K + 1;
    vector<vector<ll>> squareSum(M, vector<ll>(M, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int r1 = i, c1 = j;
            int r2 = i + K, c2 = j + K;
            squareSum[i][j] = prefix[r2][c2] - prefix[r1][c2] - prefix[r2][c1] + prefix[r1][c1];
        }
    }

    int T;
    cin >> T;

    ll maxSum = 0;

    while (T--) {
        int x, y, newVal;
        cin >> x >> y >> newVal;
        x--;
        y--;

        int oldVal = grid[x][y];
        if (oldVal != newVal) {
            ll delta = (ll)newVal - oldVal;
            int i_min = max(0, x - K + 1);
            int i_max = min(x, N - K);
            int j_min = max(0, y - K + 1);
            int j_max = min(y, N - K);

            for (int i = i_min; i <= i_max; i++) {
                for (int j = j_min; j <= j_max; j++) {
                    squareSum[i][j] += delta;
                    maxSum = max(maxSum, squareSum[i][j]);
                }
            }
            grid[x][y] = newVal;
        }

        cout << maxSum << endl;
    }
    return 0;
}