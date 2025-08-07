// https://cses.fi/problemset/task/2185
// Prime Multiples - Count integers ≤ k divisible by at least one prime using inclusion-exclusion

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    ll result = 0;

    for (int mask = 1; mask < (1 << k); mask++) {
        ll product = 1;
        int bits = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                if (product > n / primes[i]) {
                    product = n + 1;
                    break;
                }
                product *= primes[i];
                bits++;
            }
        }

        if (product <= n) {
            if (bits % 2 == 1) {
                result += n / product;
            } else {
                result -= n / product;
            }
        }
    }

    cout << result << endl;
    return 0;
}