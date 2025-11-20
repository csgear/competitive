// https://www.acwing.com/problem/content/100/
// 98. 分形之城

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> calc(ll n, ll m) {
    if (n == 0) return {0, 0};
    ll len = 1LL << (n - 1), cnt = 1LL << (2 * (n - 1));
    pair<ll, ll> res = calc(n - 1, m % cnt);
    auto [x, y] = res;
    ll z = m / cnt;
    if (z == 0) {
        return {y, x};
    } else if (z == 1) {
        return {x, y + len};
    } else if (z == 2) {
        return {x + len, y + len};
    } else {
        return {len - 1 - y + len, len - 1 - x};
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        auto [x1, y1] = calc(n, a - 1);
        auto [x2, y2] = calc(n, b - 1);
        double x = x1 - x2;
        double y = y1 - y2;
        printf("%.0lf\n", sqrt(x * x + y * y) * 10);
    }
    return 0;
}