// Euler's Totient Function φ(n) Template
// φ(n) = count of integers from 1 to n that are coprime with n

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// === METHOD 1: Direct computation using prime factorization ===
// Time: O(√n), Space: O(1)
ll phi_single(ll n) {
    ll result = n;

    // Check for factor 2
    if (n % 2 == 0) {
        while (n % 2 == 0) n /= 2;
        result -= result / 2;  // result = result * (1 - 1/2)
    }

    // Check for odd factors from 3 to √n
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;  // result = result * (1 - 1/i)
        }
    }

    // If n is still > 1, then it's a prime factor
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

// === METHOD 2: Sieve for multiple values ===
// Time: O(n log log n), Space: O(n)
// Useful when computing φ(i) for all i from 1 to n
vector<int> phi_sieve(int n) {
    vector<int> phi(n + 1);

    // Initialize phi[i] = i
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }

    // Apply Euler's formula: φ(n) = n * ∏(1 - 1/p) for all prime p | n
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {  // i is prime
            // Update φ for all multiples of i
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;  // φ(j) = φ(j) * (1 - 1/i)
            }
        }
    }

    return phi;
}

// === METHOD 3: Linear sieve (most efficient for large ranges) ===
// Time: O(n), Space: O(n)
vector<int> phi_linear_sieve(int n) {
    vector<int> phi(n + 1), primes;
    vector<bool> is_prime(n + 1, true);

    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            phi[i] = i - 1;  // φ(p) = p - 1 for prime p
        }

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            int p = primes[j];
            is_prime[i * p] = false;

            if (i % p == 0) {
                // p is already a factor of i
                phi[i * p] = phi[i] * p;
                break;
            } else {
                // p is a new prime factor
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }

    return phi;
}

// === METHOD 4: Modular version for large numbers ===
// Computes φ(n) mod m
ll phi_mod(ll n, ll mod) {
    ll result = n % mod;

    if (n % 2 == 0) {
        while (n % 2 == 0) n /= 2;
        result = (result - result / 2 + mod) % mod;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result = (result - result / i + mod) % mod;
        }
    }

    if (n > 1) {
        result = (result - result / n + mod) % mod;
    }

    return result;
}

// === USEFUL PROPERTIES AND FORMULAS ===
/*
1. φ(1) = 1
2. φ(p) = p - 1 for prime p
3. φ(p^k) = p^k - p^(k-1) = p^(k-1) * (p - 1)
4. φ(m * n) = φ(m) * φ(n) if gcd(m, n) = 1 (multiplicative function)
5. φ(n) = n * ∏(1 - 1/p) for all prime p | n
6. Sum of φ(d) for all divisors d of n equals n
7. φ(n) is even for n > 2
8. If n = p1^a1 * p2^a2 * ... * pk^ak, then
   φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
*/

// === EXAMPLE USAGE ===
int main() {
    int n;
    cin >> n;

    // Single computation
    cout << "φ(" << n << ") = " << phi_single(n) << "\n";

    // Multiple computations using sieve
    if (n <= 1000000) {
        vector<int> phi = phi_linear_sieve(n);
        cout << "φ values from 1 to " << min(n, 20) << ":\n";
        for (int i = 1; i <= min(n, 20); i++) {
            cout << "φ(" << i << ") = " << phi[i] << "\n";
        }
    }

    return 0;
}

// === COMMON APPLICATIONS ===
/*
1. Modular exponentiation: a^x ≡ a^(x mod φ(m)) (mod m) when gcd(a,m) = 1
2. Finding multiplicative order
3. RSA cryptography
4. Counting primitive roots
5. Number theory problems involving coprimality
*/
