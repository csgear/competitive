// https://atcoder.jp/contests/abc450/tasks/abc450_d
// D - Minimize Range

#include <bits/stdc++.h>
using namespace std;

int const MAXN = 200005;

int n, k;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] % k;
    }

    sort(a + 1, a + n + 1);

    int ans = a[n] - a[1];
    for (int i = 2; i <= n; i++) {
        ans = min(ans, a[i - 1] + k - a[i]);
    }

    cout << ans << "\n";
}
