// https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;

int digit(ll k) {
    k--;
    ll a = 1;
    ll b = 9;
    int c = 1;
    while (k >= (b - a + 1) * c) {
        k -= (b - a + 1) * c;
        // first number in the group 10,100,1000...
        a = a * 10;
        // last number in the group 9,99,999,9999,...
        b = b * 10 + 9;
        c++;
    }
    ll x = a + k / c;
    return to_string(x)[k % c] - '0';
}

int main() {
    fastio;

    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;
        cout << digit(k) << endl;
    }
    return 0;
}