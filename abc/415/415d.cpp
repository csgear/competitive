// https://atcoder.jp/contests/abc415/tasks/abc415_d

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> bottles(m);
    for (int i = 0; i < m; i++) {
        cin >> bottles[i].first >> bottles[i].second;
    }
    auto compare_bottles = [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return (a.first - a.second) < (b.first - b.second);
    };
    sort(bottles.begin(), bottles.end(), compare_bottles);

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        auto [a, b] = bottles[i];
        if (n < a) {
            continue;
        }
        ll d = (n - a) / (a - b) + 1;
        ans += d;
        n -= d * (a - b);
    }
    cout << ans << endl;
}