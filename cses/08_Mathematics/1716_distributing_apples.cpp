// https://cses.fi/problemset/task/1716

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e6 + 5;
const int MOD = 1e9 + 7;

ll fact[MAXN], inv_fact[MAXN];

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[n] = mod_pow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (1LL * fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials(MAXN - 1);

    int n, m;

    cin >> n >> m;

    ll result = binomial_coefficient(n + m - 1, n - 1);

    cout << result << '\n';

    return 0;
}
