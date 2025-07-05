// https://cses.fi/problemset/task/2417

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_VAL = 1e6 + 5;

// The dp[mu] array tracks how many numbers are divisible by the product of the prime factors,
// dp[1] = number of numbers divisible by 1
int dp[MAX_VAL];

// The b[i] array tracks whether i is prime
bool b[MAX_VAL];
// The primes vector stores all prime numbers up to MAX_VAL
vector<int> primes;

ll ans;
int N;

void solve() {
    int n;
    cin >> n;
    ll answer = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        vector<int> factors;
        for (int f = 2; f * f <= x; f++) {
            if (x % f == 0) {
                factors.push_back(f);
                while (x % f == 0) x /= f;
            }
        }
        if (x != 1) factors.push_back(x);

        int k = factors.size();
        for (int b = 1; b < (1 << k); b++) {
            int prod = 1;
            for (int i = 0; i < k; i++) {
                if (b & (1 << i)) prod *= factors[i];
            }

            int add = dp[prod];
            if (__builtin_parity(b) == 0) add = -add;
            answer += add;
            dp[prod]++;
        }
    }

    cout << (n * ll(n - 1) / 2) - answer << "\n";
}

void sieve() {
    fill(b + 2, b + MAX_VAL, true);
    for (int i = 2; i * i < MAX_VAL; i++) {
        if (b[i]) {
            for (int j = i * i; j < MAX_VAL; j += i) b[j] = false;
        }
    }
    for (int i = 2; i < MAX_VAL; i++) {
        if (b[i]) primes.push_back(i);
    }
}

void compute(int x) {
    vector<int> pf;
    for (int p : primes) {
        if (x == 1)
            break;
        else if (b[x]) {
            pf.push_back(x);
            break;
        }

        if (x % p) continue;
        pf.push_back(p);
        while (x % p == 0) x /= p;
    }

    int K = (int)pf.size();

    // inclusion-exclusion principle
    // for each subset of prime factors, compute the product of the prime factors
    // and add the number of numbers divisible by the product to the answer
    // if the number of prime factors is odd, subtract the number of numbers divisible by the
    // product if the number of prime factors is even, add the number of numbers divisible by
    // the product
    for (int mask = 0; mask < (1 << K); mask++) {
        int mu = 1;
        // Calculates Möbius function: For each subset:
        // mu = product of selected prime factors
        // k = number of prime factors in the subset (using __builtin_popcount)
        for (int i = 0; i < K; i++)
            if (mask & (1 << i)) mu *= pf[i];
        int k = __builtin_popcount(mask);
        ans += (k & 1 ? -dp[mu] : dp[mu]);
        dp[mu]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}