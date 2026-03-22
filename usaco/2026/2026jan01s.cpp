
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int T;

void solve1() {
    ll c, t;
    cin >> c >> t;
    ll time = c, pos = c;
    while (time < t) {
        if (pos > (time + 1) / 2) {
            time = 2 * pos - 1;
        } else if (pos) {
            ll delta = min(pos, t - time);
            time += delta;
            pos -= delta;
        } else {
            pos = ++time / 2;
        }
    }
    cout << pos << '\n';
}

void solve2() {}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        int q;
        cin >> q;
        if (q == 1) {
            solve1();
        } else {
            solve2();
        }
    }
    return 0;
}