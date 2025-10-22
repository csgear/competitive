// https://usaco.org/index.php?page=viewproblem2&cpid=1443

// USACO 2024 December Contest, Bronze
// Problem 1. Roundabout Rounding

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll count = 0;
        for (int i = 2; i <= 10; i++) {
            ll power10 = 1;
            for (int j = 0; j < i - 1; j++) power10 *= 10;

            ll upper = 4 * power10 + power10 - 1;
            ll lower = 4 * power10 * 10 / 9;

            if (n > upper) {
                ll fives = 5 * (power10 - 1) / 9;
                count += fives;
            } else if (n > lower) {
                count += n - lower;
            }
        }
        cout << count << "\n";
    }
    return 0;
}