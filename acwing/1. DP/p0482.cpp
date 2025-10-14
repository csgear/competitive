// https://www.acwing.com/problem/content/484/
// LIS

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int f[N], g[N];
int n, h[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    f[0] = g[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (h[i] > h[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j >= i; j--) {
            if (h[i] > h[j]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}