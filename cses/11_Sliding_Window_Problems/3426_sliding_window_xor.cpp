// https://cses.fi/problemset/task/3426

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    ll windowXor = 0, ans = 0;
    queue<ll> q;

    for (int i = 0; i < k; i++) {
        windowXor ^= x;
        q.push(x);
        x = (x * a + b) % c;
    }
    ans = windowXor;

    for (int i = k; i < n; i++) {
        windowXor ^= q.front();
        q.pop();

        windowXor ^= x;
        q.push(x);

        ans ^= windowXor;

        x = (x * a + b) % c;
    }

    cout << ans << endl;
    return 0;
}