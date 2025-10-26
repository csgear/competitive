// https://www.acwing.com/problem/content/1060/
// Stock trading with cooldown period
// State machine: f[i][0] = holding, f[i][1] = sold today, f[i][2] = cooldown
// Must wait one day after selling before buying again

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 0x3f3f3f3f;

// 0 hold stock, 1 sold today, 2 cooldown
int f[N][3];

int n, k, w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    f[0][0] = f[0][1] = -INF;

    f[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }

    cout << max(f[n][1], f[n][2]) << endl;
    return 0;
}