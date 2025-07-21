// https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            pre[i][j] += (row[j - 1] == '*') ? 1 : 0;
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int res = pre[y2][x2] - pre[y1 - 1][x2] - pre[y2][x1 - 1] + pre[y1 - 1][x1 - 1];
        cout << res << '\n';
    }
    return 0;
}