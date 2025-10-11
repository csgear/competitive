// https://www.acwing.com/problem/content/92/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll modmul(ll a, ll b, ll p) {
    ll res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % p;
        }
        a = (a * 2) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, p;
    cin >> a >> b >> p;

    ll ans = 0;
    ans = modmul(a, b, p);
    cout << ans << '\n';
    return 0;
}