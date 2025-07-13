// https://atcoder.jp/contests/abc414/tasks/abc414_e

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll INV2 = 499122177;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ans = (n % MOD) * (n % MOD) % MOD;
    ans -= ((n - 1)) % MOD * (n % MOD) % MOD * INV2 % MOD;

    for (ll l = 1; l <= n;) {
        ll k = n / l;
        ll r = n / k;
        ans -= (k % MOD) * ((r - l + 1) % MOD) % MOD;
        ans = (ans + MOD) % MOD;
        l = r + 1;
    }
    cout << ans << endl;

    return 0;
}