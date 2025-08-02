// https://cses.fi/problemset/task/3405

// TLE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> bitCount(32, 0);
    queue<ll> window;
    ll ans = 0;

    auto getOR = [&]() -> ll {
        ll orVal = 0;
        for (int bit = 0; bit < 32; ++bit) {
            if (bitCount[bit] > 0) {
                orVal |= (1LL << bit);
            }
        }
        return orVal;
    };

    for (int i = 0; i < k; ++i) {
        window.push(x);
        for (int bit = 0; bit < 32; ++bit) {
            if (x & (1LL << bit)) {
                bitCount[bit]++;
            }
        }
        x = (x * a + b) % c;
    }
    ans = getOR();

    for (int i = k; i < n; ++i) {
        ll front = window.front();
        window.pop();
        for (int bit = 0; bit < 32; ++bit) {
            if (front & (1LL << bit)) {
                bitCount[bit]--;
            }
        }

        window.push(x);

        for (int bit = 0; bit < 32; ++bit) {
            if (x & (1LL << bit)) {
                bitCount[bit]++;
            }
        }

        ans ^= getOR();
        x = (x * a + b) % c;
    }

    cout << ans << endl;
    return 0;
}