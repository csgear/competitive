// https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    long long result = 1;

    result = mod_pow(2, n, MOD);

    cout << result << endl;

    return 0;
}