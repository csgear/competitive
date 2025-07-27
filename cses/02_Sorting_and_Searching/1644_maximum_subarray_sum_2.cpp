// https://cses.fi/problemset/task/1644

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + arr[i];
    ll ans = LLONG_MIN;
    multiset<ll> window;
    for (int i = a; i <= n; ++i) {
        if (i > b) window.erase(window.find(prefix[i - b - 1]));
        window.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *window.begin());
    }
    cout << ans << '\n';
    return 0;
}