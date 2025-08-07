// https://cses.fi/problemset/task/1095

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
        ll a, b;
        cin >> a >> b;
        cout << mod_exp(a, b, MOD) << '\n';
    }
    return 0;
}