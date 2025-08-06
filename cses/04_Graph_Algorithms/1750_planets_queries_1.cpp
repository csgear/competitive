// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    const int MAXLOG = 30;
    vector<vector<int>> lift(MAXLOG, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        cin >> lift[0][i];
    }

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            // lift[i-1][j] is the planet after 2^(i-1) steps from j
            // lift[i][j] is the planet after 2^i steps from j
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;

        for (int bit = 0; bit < MAXLOG && k > 0; bit++) {
            if (k & (1 << bit)) {
                x = lift[bit][x];
                k ^= (1 << bit);
            }
        }

        cout << x << "\n";
    }

    return 0;
}