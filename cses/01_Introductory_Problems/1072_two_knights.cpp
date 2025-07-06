// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;

int main() {
    fastio;

    int n;
    cin >> n;

    for (ll k = 1; k <= n; k++) {
        // total number of ways to place two knights on a k x k board
        ll total = (k * k * (k * k - 1)) / 2;
        // number of ways to place two knights that attack each other
        ll attack = 4LL * (k - 1) * (k - 2);
        // number of ways to place two knights that do not attack each other
        cout << total - attack << endl;
    }
    return 0;
}
