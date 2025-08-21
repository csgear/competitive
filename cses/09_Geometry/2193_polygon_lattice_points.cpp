// https://cses.fi/problemset/task/2193

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    ll area2 = 0;
    ll boundary = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area2 += x[i] * y[j] - x[j] * y[i];
        ll dx = abs(x[j] - x[i]);
        ll dy = abs(y[j] - y[i]);
        boundary += gcd(dx, dy);
    }
    area2 = abs(area2);
    ll interior = (area2 - boundary) / 2 + 1;
    cout << interior << " " << boundary << '\n';
    return 0;
}
