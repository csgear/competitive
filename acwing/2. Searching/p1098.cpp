// https://www.acwing.com/problem/content/1100/

#include <bits/stdc++.h>
using namespace std;

const int N = 100;

char g[N][N];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int x;

    memset(g, '.', sizeof g);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x;
            if (x & 1) {
                g[i][j - 1] = '#';
            }
            if (x & 2) {
                g[i - 1][j] = '#';
            }
            if (x & 4) {
                g[i][j + 1] = '#';
            }
            if (x & 8) {
                g[i + 1][j] = '#';
            }
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}