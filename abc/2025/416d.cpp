// https://atcoder.jp/contests/abc416/tasks/abc416_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] % m;
        ans += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = b[i] % m;
        ans += b[i];
    }

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    int cnt = 0;
    for (int i = 1, j = n; i <= n; i++) {
        if (a[i] + b[j] >= m) {
            j--;
            ans -= m;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}