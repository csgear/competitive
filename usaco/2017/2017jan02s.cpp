// https://usaco.org/index.php?page=viewproblem2&cpid=691
// USACO 2017 January Contest, Silver
// Problem 2. Hoof, Paper, Scissors

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int pre[N][3];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        pre[i][0] = pre[i - 1][0] + (c == 'H');
        pre[i][1] = pre[i - 1][1] + (c == 'P');
        pre[i][2] = pre[i - 1][2] + (c == 'S');
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int before = max({pre[i][0], pre[i][1], pre[i][2]});
        int after = max({pre[n][0] - pre[i][0], pre[n][1] - pre[i][1], pre[n][2] - pre[i][2]});
        ans = max(ans, before + after);
    }

    cout << ans << endl;
}