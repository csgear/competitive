// https://cses.fi/problemset/task/1717

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll derangement_mod(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    ll d0 = 1;
    ll d1 = 0;
    for (int i = 2; i <= n; i++) {
        ll di = (i - 1) * (d0 + d1) % MOD;
        d0 = d1;
        d1 = di;
    }

    return d1;
}

int main() {
    int n;
    cin >> n;
    cout << derangement_mod(n) << endl;
    return 0;
}