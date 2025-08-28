// https://www.luogu.com.cn/problem/P1102

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5 + 5;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r1 = 1, r2 = 1;
    ll ans = 0;
    for (l = 1; l <= n; l++) {
        // 2-points, find the range in a,
        // such that a[r2] - a[l] == c and a[r1] - a[l] < c
        while (r1 <= n && a[r1] - a[l] < c) r1++;
        while (r1 <= n && a[r1] - a[l] == c) {
            r1++;
            ans++;
        }
    }
    cout << ans;
    return 0;
}