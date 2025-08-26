// https://atcoder.jp/contests/abc420/tasks/abc420_g

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL x;
    cin >> x;

    vector<LL> res;

    LL target = 1 - 4 * x;

    vector<LL> divisors;
    for (LL d = 1; d * d <= abs(target); d++) {
        if (target % d == 0) {
            divisors.push_back(d);
            divisors.push_back(-d);
            if (d != abs(target) / d) {
                divisors.push_back(target / d);
                divisors.push_back(-target / d);
            }
        }
    }

    for (LL a : divisors) {
        LL b = target / a;
        if ((a + b) % 2 == 0 && (b - a) % 4 == 0) {
            LL m = (a + b) / 2;
            if (m % 2 != 0) {
                LL n = (m - 1) / 2;
                res.push_back(n);
            }
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    if (!res.empty()) cout << "\n";

    return 0;
}