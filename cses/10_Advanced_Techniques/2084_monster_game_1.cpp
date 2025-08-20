// https://cses.fi/problemset/task/2084

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Line {
    ll m, b;
    ll eval(ll x) { return m * x + b; }
};

bool bad(Line a, Line b, Line c) { return (c.b - a.b) * (a.m - b.m) <= (b.b - a.b) * (a.m - c.m); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> s(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> f[i];

    vector<ll> dp(n + 1, LLONG_MAX);
    deque<Line> hull;

    // Base case: start with initial skill factor x
    dp[0] = 0;
    hull.push_back({x, 0});

    for (int i = 1; i <= n; i++) {
        while (hull.size() >= 2 && hull[0].eval(s[i]) >= hull[1].eval(s[i])) {
            hull.pop_front();
        }

        dp[i] = hull[0].eval(s[i]);

        Line newLine = {f[i], dp[i]};
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], newLine)) {
            hull.pop_back();
        }
        hull.push_back(newLine);
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    cout << dp[n] << '\n';
}