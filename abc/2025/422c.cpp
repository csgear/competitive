// https://atcoder.jp/contests/abc422/tasks/abc422_c

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll na, nb, nc;
        ll ans = 0;
        cin >> na >> nb >> nc;
        if (na > nc) swap(na, nc);

        ans = min(na, (na + nb + nc) / 3);

        cout << ans << endl;
    }
    return 0;
}