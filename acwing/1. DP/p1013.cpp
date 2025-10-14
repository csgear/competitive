// https://www.acwing.com/problem/content/1015/

#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 20;

int w[N][M];
int f[N][M];
int way[N];

int n, m;

// group knapsack
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }

    cout << f[n][m] << '\n';
    int j = m;
    for (int i = n; i >= 1; i--) {
        for (int k = 0; k <= j; k++) {
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) {
                way[i] = k;
                j -= k;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << way[i] << '\n';
    }

    return 0;
}