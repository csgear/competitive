#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;
vector<ll> s1, s2;
vector<string> g;
vector<int> up, L, R;
vector<int> stk;

ll cal(ll a, ll b, ll h, ll w0, ll w1, ll w2) {
    if (w1 > w2) return 0;
    ll res = 0;

    ll r1 = min((ll)w2, w0);
    if (w1 <= r1) {
        ll cnt = r1 - w1 + 1;
        ll sum = (w1 + r1) * cnt / 2;
        res += h * (a * sum + b * cnt);
    }

    ll l2 = max((ll)w1, w0 + 1);
    if (l2 <= w2) {
        ll p1 = s1[w2] - s1[l2 - 1];
        ll p2 = s2[w2] - s2[l2 - 1];
        res += a * p2 + b * p1;
    }
    return res;
}

void slv() {
    ll ans = 0;
    up.assign(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                up[j]++;
            } else {
                up[j] = 0;
            }
        }

        stk.clear();
        for (int j = 0; j < m; ++j) {
            while (!stk.empty() && up[stk.back()] >= up[j]) {
                stk.pop_back();
            }
            L[j] = stk.empty() ? -1 : stk.back();
            stk.push_back(j);
        }

        stk.clear();
        for (int j = m - 1; j >= 0; --j) {
            while (!stk.empty() && up[stk.back()] > up[j]) {
                stk.pop_back();
            }
            R[j] = stk.empty() ? m : stk.back();
            stk.push_back(j);
        }

        for (int j = 0; j < m; ++j) {
            if (up[j] == 0) continue;

            ll h = up[j];
            ll l1 = j - L[j];
            ll l2 = R[j] - j;

            if (l1 > l2) swap(l1, l2);

            ll w0 = k / h;

            ans += cal(1, 0, h, w0, 1, l1);
            ans += cal(0, l1, h, w0, l1 + 1, l2);
            ans += cal(-1, l1 + l2, h, w0, l2 + 1, l1 + l2 - 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    g.resize(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    s1.resize(m + 1, 0);
    s2.resize(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        ll v = k / i;
        s1[i] = s1[i - 1] + v;
        s2[i] = s2[i - 1] + v * i;
    }

    L.resize(m);
    R.resize(m);

    slv();

    return 0;
}