// https://cses.fi/problemset/task/1729
// Stick Game - Grundy Numbers (Sprague-Grundy Theorem)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> moves(k);
    for (int i = 0; i < k; i++) {
        cin >> moves[i];
    }

    vector<int> grundy(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<bool> seen(k + 1, false);

        for (int move : moves) {
            if (i >= move && grundy[i - move] <= k) {
                seen[grundy[i - move]] = true;
            }
        }

        int mex = 0;
        while (mex <= k && seen[mex]) {
            mex++;
        }
        grundy[i] = mex;
    }

    for (int i = 1; i <= n; i++) {
        cout << (grundy[i] == 0 ? 'L' : 'W');
    }
    cout << '\n';

    return 0;
}