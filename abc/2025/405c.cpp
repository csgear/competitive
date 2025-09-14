// https://atcoder.jp/contests/abc405/tasks/abc405_c

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 5;

ll a[N], pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0;
    for (int j = 2; j <= n; j++) {
        ans += a[j] * pre[j - 1];
    }
    cout << ans << endl;
    return 0;
}