// https://atcoder.jp/contests/abc422/tasks/abc422_e

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> pt(n);

    for (int i = 0; i < n; i++) {
        cin >> pt[i].first >> pt[i].second;
    }

    auto check = [&](int i, int j) {
        if (i == j) return false;
        auto [x1, y1] = pt[i];
        auto [x2, y2] = pt[j];
        ll a = y2 - y1;
        ll b = x1 - x2;
        ll c = x2 * y1 - x1 * y2;
        ll cnt = count_if(pt.begin(), pt.end(), [&](auto& p) {
            auto [x, y] = p;
            return a * x + b * y + c == 0;
        });
        if (cnt >= (n + 1) / 2) {
            cout << "Yes" << endl;
            cout << a << " " << b << " " << c << endl;
            return true;
        }
        return false;
    };

    int time = 100;

    while (time--) {
        int i = rand() % n;
        int j = rand() % n;
        if (check(i, j)) {
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}