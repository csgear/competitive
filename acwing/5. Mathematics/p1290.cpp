// https://www.acwing.com/problem/content/1292/
// 1290. 越狱

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 100003;

ll m, n;

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> m >> n;
    ll res = ((mod_pow(m, n) - m * mod_pow(m - 1, n - 1) % MOD + MOD) % MOD);
    cout << res << endl;
    return 0;
}