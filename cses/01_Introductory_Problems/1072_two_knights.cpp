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
        // C(k^2, 2)
        ll total = (k * k * (k * k - 1)) / 2;

        // number of ways to place two knights that attack each other
        // Knights attack each other in L-shape: 2x3 or 3x2 rectangles
        // In a kxk board, there are (k-1)*(k-2) 2x3 rectangles and (k-2)*(k-1) 3x2 rectangles
        // Each rectangle has 2 ways to place attacking knights
        // Total attacking positions: 2*(k-1)*(k-2) + 2*(k-2)*(k-1) = 4*(k-1)*(k-2)
        ll attack = 4LL * (k - 1) * (k - 2);
        // number of ways to place two knights that do not attack each other
        cout << total - attack << endl;
    }
    return 0;
}
