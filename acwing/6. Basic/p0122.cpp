// https://www.acwing.com/problem/content/description/124/
// 122. 糖果传递

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000000 + 10;

int n;

ll solve() {
    cin >> n;
    vector<ll> a(n + 1);
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }

    if (total % n != 0) return -1;

    ll avg = total / n;

    vector<ll> c(n);

    c[0] = 0;

    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1] + a[i] - avg;
    }

    // find median
    nth_element(c.begin(), c.begin() + n / 2, c.end());

    ll median = c[n / 2];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(c[i] - median);
    }
    return res;
}

int main() {
    ll res = solve();
    cout << res << endl;
    return 0;
}