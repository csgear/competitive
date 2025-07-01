// https://cses.fi/problemset/task/1146

#include <bits/stdc++.h>
using namespace std;

long long count_digit(long long n, int digit) {
    long long res = 0, factor = 1;
    while (n / factor > 0) {
        long long lower = n % factor;
        long long curr = (n / factor) % 10;
        long long higher = n / (factor * 10);

        if (curr < digit)
            res += higher * factor;
        else if (curr == digit)
            res += higher * factor + lower + 1;
        else
            res += (higher + 1) * factor;

        factor *= 10;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < 60; ++i) {
        // for ith bit, we count the number of blocks of size 2^(i+1)
        long long block = (n + 1) / (1LL << (i + 1));
        res += block * (1LL << i);
        // for the remaining part, we count the number of bits that are set
        // the pattern is 2^i 0s, 2^i 1s, 2^i 0s, 2^i 1s, ...
        // so we need to subtract the number of 0s in the remaining parts
        long long rem = (n + 1) % (1LL << (i + 1));
        if (rem > (1LL << i)) res += rem - (1LL << i);
    }
    cout << res << endl;
    return 0;
}