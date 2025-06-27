// https://www.luogu.com.cn/problem/P1102

#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

constexpr int MAXN = 2e5 + 5;

int a[MAXN];

int main() {
    fastio;

    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r1 = 1, r2 = 1;
    ll ans = 0;
    for (l = 1; l <= n; l++) {
        while (r1 <= n && a[r1] - a[l] < c) r1++;
        while (r2 <= n && a[r2] - a[l] <= c) r2++;
        if (a[r1] - a[l] == c && a[r2 - 1] - a[l] == c) {
            ans += r2 - r1;
        }
    }
    cout << ans;
    return 0;
}