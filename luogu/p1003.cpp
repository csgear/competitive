// https://www.luogu.com.cn/problem/P1003

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int MAXN = 10000 + 5;
int a[MAXN], b[MAXN], g[MAXN], k[MAXN];

int main() {
    fastio;

    int n, x, y;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }

    cin >> x >> y;

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}