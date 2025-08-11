// https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp, int mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;

        // We need to compute a^(b^c) mod MOD
        // Using Euler's theorem: a^(b^c) ≡ a^(b^c mod φ(MOD)) (mod MOD)
        // Since MOD = 10^9 + 7 is prime, φ(MOD) = MOD - 1

        ll exponent = mod_exp(b, c, MOD - 1);   // b^c mod (MOD-1)
        ll result = mod_exp(a, exponent, MOD);  // a^exponent mod MOD

        cout << result << '\n';
    }
    return 0;
}