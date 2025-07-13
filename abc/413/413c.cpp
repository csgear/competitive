// https://atcoder.jp/contests/abc413/tasks/abc413_c

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

queue<pair<ll, ll>> q;

int main() {
    int query;
    cin >> query;
    ll ans = 0;
    while (query--) {
        int type;
        cin >> type;
        if (type == 1) {
            int c, x;
            cin >> c >> x;
            q.push({c, x});
        } else if (type == 2) {
            int k;
            cin >> k;
            ans = 0;
            while (k > 0) {
                auto [c, x] = q.front();
                if (c <= k) {
                    k -= c;
                    ans += x * c;
                    q.pop();
                } else {
                    ans += x * k;
                    c -= k;
                    q.front().first = c;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
