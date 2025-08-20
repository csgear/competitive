// https://cses.fi/problemset/task/2194/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Point pair<ll, ll>

ll dist2(Point a, Point b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    set<Point> s;
    s.insert({p[0].second, p[0].first});
    ll ans = LLONG_MAX;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        ll d = ceil(sqrt(ans));
        while (j < i && p[j].first < p[i].first - d) {
            s.erase({p[j].second, p[j].first});
            ++j;
        }
        auto lo = s.lower_bound({p[i].second - d, -1e18});
        auto hi = s.upper_bound({p[i].second + d, 1e18});
        for (auto it = lo; it != hi; ++it) {
            ans = min(ans, dist2({it->second, it->first}, p[i]));
        }
        s.insert({p[i].second, p[i].first});
    }

    cout << ans << '\n';
    return 0;
}