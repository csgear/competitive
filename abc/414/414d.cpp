// https://atcoder.jp/contests/abc414/tasks/abc414_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    ll ans = a[n] - a[1];

    // build dist array
    priority_queue<ll> pq;
    for (int i = 2; i <= n; i++) {
        pq.push(a[i] - a[i - 1]);
    }

    // pop n - m + 1 elements
    for (int i = 1; i <= m - 1; i++) {
        ans -= pq.top();
        pq.pop();
    }

    cout << ans << endl;
    return 0;
}
