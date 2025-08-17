// https://atcoder.jp/contests/abc408/tasks/abc408_g

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    function<void(long long, long long, long long &, long long &, long long, long long)> f =
        [&](long long a, long long b, long long &p, long long &q, long long c, long long d) {
            if (a < b && c > d) {
                return p = 1, q = 1, void();
            }
            f(d % c, c, q, p, b - d / c * a, a), q += d / c * p;
        };

    int t;
    cin >> t;
    while (t--) {
        long long A, B, C, D, P, Q;
        cin >> A >> B >> C >> D;
        f(A, B, P, Q, C, D);
        cout << Q << '\n';
    }

    return 0;
}