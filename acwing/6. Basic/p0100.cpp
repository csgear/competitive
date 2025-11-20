// https://www.acwing.com/problem/content/102/
// 100. 增减序列

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll a[N], p, q;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        ll diff = a[i] - a[i - 1];
        if (diff > 0) {
            p += diff;
        } else {
            q -= diff;
        }
    }

    ll ans1 = max(p, q);
    ll ans2 = abs(p - q) + 1;

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}