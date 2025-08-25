// https://cses.fi/problemset/task/2191

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
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area2 += x[i] * y[j] - x[j] * y[i];
    }
    area2 = abs(area2);
    cout << area2 << '\n';
    return 0;
}
