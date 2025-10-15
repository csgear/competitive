// https://cses.fi/problemset/task/3169

// CSES 3169 Counting LCM Arrays

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

map<ll, int> factorize(ll k) {
    map<ll, int> factors;
    ll d = 2;
    while (d * d <= k) {
        while (k % d == 0) {
            factors[d]++;
            k /= d;
        }
        d++;
    }
    if (k > 1) factors[k]++;
    return factors;
}

vector<vector<ll>> mat_mult(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> C(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> base, ll power) {
    vector<vector<ll>> res = {{1, 0}, {0, 1}};
    while (power > 0) {
        if (power & 1) {
            res = mat_mult(res, base);
        }
        base = mat_mult(base, base);
        power >>= 1;
    }
    return res;
}

ll f(int e, ll n) {
    // M = [[1, 1], [e, 0]]
    vector<vector<ll>> M = {{1, 1}, {(ll)e, 0}};
    vector<vector<ll>> M_exp = mat_pow(M, n - 1);

    ll a1 = 1;
    ll b1 = e;

    ll a_n = (M_exp[0][0] * a1 + M_exp[0][1] * b1) % MOD;
    ll b_n = (M_exp[1][0] * a1 + M_exp[1][1] * b1) % MOD;

    return (a_n + b_n) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        auto factors = factorize(k);
        ll ans = 1;
        for (auto& [p, exp] : factors) {
            ans = (ans * f(exp, n)) % MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}