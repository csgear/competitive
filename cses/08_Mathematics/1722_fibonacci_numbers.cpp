// https://cses.fi/problemset/task/1722

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Fast doubling method for Fibonacci with modular arithmetic
// return f(n) and f(n+1)
pair<ll, ll> fib(ll n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib(n >> 1);
    // f(2k) = f(k) * (2 * f(k+1) - f(k))
    ll c = (a * ((2 * b - a + MOD) % MOD)) % MOD;
    // f(2k+1) = f(k)^2 + f(k+1)^2
    ll d = ((a * a) % MOD + (b * b) % MOD) % MOD;

    if (n & 1)
        // n is odd, return f(2k+1) and f(2k+2)
        return {d, (c + d) % MOD};
    else
        // n is even, return f(2k) and f(2k+1)
        return {c, d};
}

ll fibonacci(ll n) { return fib(n).first; }

int main() {
    ll n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}