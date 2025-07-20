// https://cses.fi/problemset/task/1628

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int m = n / 2;
    vector<ll> t1(1 << m);
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                t1[i] += t[j];
            }
        }
    }
    sort(t1.begin(), t1.end());

    ll ans = 0;

    for (int i = 0; i < (1 << (n - m)); i++) {
        ll t2 = 0;
        for (int j = 0; j < (n - m); j++) {
            if (i & (1 << j)) {
                t2 += t[j + m];
            }
        }
        ans +=
            upper_bound(t1.begin(), t1.end(), k - t2) - lower_bound(t1.begin(), t1.end(), k - t2);
    }
    cout << ans << endl;
    return 0;
}