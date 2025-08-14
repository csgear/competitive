// https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll zeros = 0;

    // n/5: Numbers divisible by 5 (contribute one factor of 5 each)
    // n/25: Numbers divisible by 25 (contribute an additional factor of 5)
    for (ll i = 5; n / i > 0; i *= 5) {
        zeros += n / i;
    }
    cout << zeros << '\n';
    return 0;
}
