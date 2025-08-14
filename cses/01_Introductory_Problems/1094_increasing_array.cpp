// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll prev = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x < prev) {
            ans += prev - x;
        } else {
            prev = x;
        }
    }
    cout << ans << endl;
    return 0;
}