// https://cses.fi/problemset/task/1082
// Sum of Divisors - Advanced Number Theory

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;  // Modular inverse of 2 (since MOD is prime)

/*
 * PROBLEM: Calculate sum of all divisors of all numbers from 1 to n
 *
 * NAIVE APPROACH: O(n√n) - too slow for n ≤ 10^12
 * for i = 1 to n:
 *     for j = 1 to √i:
 *         if i % j == 0: add j and i/j to sum
 *
 * KEY INSIGHT: Instead of "for each number, find its divisors",
 * think "for each divisor d, count how many numbers ≤ n it divides"
 *
 * MATHEMATICAL FOUNDATION:
 * - Divisor d appears in numbers: d, 2d, 3d, ..., kd where kd ≤ n
 * - So d appears exactly ⌊n/d⌋ times
 * - Contribution of divisor d = d × ⌊n/d⌋
 * - Total sum = Σ(d=1 to n) d × ⌊n/d⌋
 *
 * OPTIMIZATION: Divisor sum technique
 * - Key observation: ⌊n/d⌋ takes only O(√n) distinct values!
 * - For many consecutive values of d, ⌊n/d⌋ is the same
 * - Group these consecutive d values and calculate their sum efficiently
 */

int main() {
    ll n;
    cin >> n;

    ll ans = 0;

    // DIVISOR SUM TECHNIQUE: Process ranges where ⌊n/d⌋ is constant
    for (ll d = 1; d <= n;) {
        ll q = n / d;  // Current quotient ⌊n/d⌋

        // Find the largest d' such that ⌊n/d'⌋ = q
        // This happens when n/d' ≥ q, so d' ≤ n/q
        // The next different quotient starts at d = n/q + 1
        ll next_d = n / q + 1;
        ll last_d = min(next_d - 1, n);  // Last d in current range

        /*
         * RANGE CALCULATION:
         * All d from current_d to last_d have the same quotient q = ⌊n/d⌋
         *
         * Contribution = (d + (d+1) + ... + last_d) × q
         *              = (sum from d to last_d) × q
         *
         * Sum from d to last_d = Sum(1 to last_d) - Sum(1 to d-1)
         *                      = last_d×(last_d+1)/2 - (d-1)×d/2
         */

        // Calculate sum of arithmetic sequence from d to last_d
        ll sum_range = ((last_d % MOD) * ((last_d + 1) % MOD) % MOD -
                        ((d - 1) % MOD) * (d % MOD) % MOD + MOD) %
                       MOD;

        // Divide by 2 using modular inverse (since we're in mod arithmetic)
        sum_range = (sum_range * INV2) % MOD;

        // Add contribution: (sum of divisors in range) × (how many times each appears)
        ans = (ans + (sum_range * (q % MOD)) % MOD) % MOD;

        // Move to next range
        d = next_d;
    }

    cout << ans << endl;
    return 0;
}