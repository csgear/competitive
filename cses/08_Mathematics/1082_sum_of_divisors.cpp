// https://cses.fi/problemset/task/1082

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;

int main() {
    ll n;
    cin >> n;

    ll ans = 0;

    for (ll d = 1; d <= n;) {
        ll q = n / d;
        ll next_d = n / q + 1;
        ll last_d = min(next_d - 1, n);

        // Sum = sum of 1 to last_d - sum of 1 to (d-1) = sum from d to last_d
        ll sum_range = ((last_d % MOD) * ((last_d + 1) % MOD) % MOD -
                        ((d - 1) % MOD) * (d % MOD) % MOD + MOD) %
                       MOD;
        sum_range = (sum_range * INV2) % MOD;

        // Add contribution: sum_range * q
        ans = (ans + (sum_range * (q % MOD)) % MOD) % MOD;

        d = next_d;
    }

    cout << ans << endl;
    return 0;
}