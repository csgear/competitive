// https://www.acwing.com/problem/content/1051/
// Stock trading with unlimited transactions
// State machine DP: f[i][0] = max profit at day i not holding stock
// f[i][1] = max profit at day i holding stock

#include <bits/stdc++.h>
using namespace std;

const int T = 50 + 5;
const int N = 1e5 + 5;

int t, n, a[N];
int f[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        memset(f, -0x3f, sizeof(f));

        f[0][0] = 0;
        f[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + a[i];
        }

        cout << max(f[n][0], f[n][1]) << endl;
    }

    return 0;
}