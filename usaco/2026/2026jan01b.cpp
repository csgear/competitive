
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve() {
    ll a, b, ca, cb, fa;
    cin >> a >> b >> ca >> cb >> fa;

    a += b / cb * ca;
    b = b % cb;

    if (a >= fa) {
        return 0;
    }

    ll ans = cb - b - 1;
    b = cb - 1;
    ll ci = (fa - a - 1) / ca;
    if (ca < cb) {
        ans += ci * cb;
        a += ci * ca;
        return ans += fa - a;
    } else {
        return ans += fa - a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}