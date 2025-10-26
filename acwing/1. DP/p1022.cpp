// https://www.acwing.com/problem/content/1024/
// 2D bounded knapsack problem
// Two capacity constraints (volume and weight)
// State: f[i][j] = max value with volume ≤ i and weight ≤ j

#include <bits/stdc++.h>
using namespace std;

const int K = 110, N = 1010, M = 510;

int f[N][M];
int v1[K], v2[K];

int n, m, k;

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) cin >> v1[i] >> v2[i];

    for (int i = 1; i <= k; i++) {
        for (int j = n; j >= v1[i]; j--) {
            for (int u = m - 1; u >= v2[i]; u--) {
                f[j][u] = max(f[j][u], f[j - v1[i]][u - v2[i]] + 1);
            }
        }
    }

    cout << f[n][m - 1] << " ";

    int res = m - 1;
    for (int j = 0; j < m - 1; j++) {
        if (f[n][j] == f[n][m - 1]) {
            res = min(res, j);
        }
    }
    cout << m - res << endl;
    return 0;
}
