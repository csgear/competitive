// https://cses.fi/problemset/task/3221

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    ll ans = 0;
    deque<pair<ll, int>> dq;  // {value, index}

    for (int i = 0; i < n; i++) {
        // remove front elements which are out of the sliding window
        while (!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }

        // keep the queue in increasing order, which ensures the front is the minimum
        while (!dq.empty() && dq.back().first >= x) {
            dq.pop_back();
        }

        dq.push_back({x, i});

        // and the front of the deque will always be the minimum in the current window
        if (i >= k - 1) {
            ans = ans ^ dq.front().first;
        }

        x = (x * a + b) % c;
    }

    cout << ans << endl;
    return 0;
}