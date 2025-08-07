// https://cses.fi/problemset/task/2182
// Divisor Analysis - Calculate number, sum, and product of all divisors

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inv(ll a) { return mod_exp(a, MOD - 2, MOD); }

int main() {
    int n;
    cin >> n;

    vector<ll> p(n), k(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> k[i];
    }

    ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;

    for (int i = 0; i < n; i++) {
        div_cnt = div_cnt * (k[i] + 1) % MOD;
        div_sum = div_sum * (mod_exp(p[i], k[i] + 1, MOD) - 1 + MOD) % MOD *
                  mod_inv(p[i] - 1 + MOD) % MOD;
        div_prod = mod_exp(div_prod, k[i] + 1, MOD) *
                   mod_exp(mod_exp(p[i], (k[i] * (k[i] + 1) / 2) % (MOD - 1), MOD), div_cnt2, MOD) %
                   MOD;
        div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);
    }

    cout << div_cnt << ' ' << div_sum << ' ' << div_prod << endl;
    return 0;
}