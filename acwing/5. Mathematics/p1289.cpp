// https://www.acwing.com/problem/content/1291/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 200907;

ll f(ll x, ll y) {
    ll b = 1;
    while (y) {
        if (y & 1) b = b * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return b;
}

int main() {
    ll n, a, b, c, k;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> k;
        ll ans = 0;
        if (a + c == 2 * b) {
            ans = (a + (b - a) * (k - 1)) % MOD;
        } else {
            ans = a * f(b / a, k - 1) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}