
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    // Start with n*k (maximum possible sum if all gcd(i,k) = k)
    ll ans = n * k;

    // Use integer division blocking to optimize
    // For each block where k/i has the same value, process together
    for (ll l = 1, r; l <= n; l = r + 1) {
        if (k / l != 0) {
            // Find the right boundary where k/i has the same value as k/l
            r = min(n, k / (k / l));
        } else {
            // When k/l = 0, all remaining terms contribute 0
            r = n;
        }
        // Subtract the sum: (k/l) * count_of_terms
        // For all i in [l, r], k/i = k/l, so subtract (k/l) * (r - l + 1)
        ans -= (k / l) * (r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}