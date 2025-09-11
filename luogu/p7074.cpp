// https://www.luogu.com.cn/problem/P7074

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    constexpr ll inf = LLONG_MIN / 2;
    vector<ll> up(n, inf), down(n, inf);
    up[0] = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            up[i] = down[i] = max(up[i], down[i]) + g[i][j];
        }
        for (int i = 1; i < n; i++) {
            down[i] = max(down[i], down[i - 1] + g[i][j]);
        }
        for (int i = n - 2; i >= 0; i--) {
            up[i] = max(up[i], up[i + 1] + g[i][j]);
        }
    }

    cout << down[n - 1] << endl;
    return 0;
}