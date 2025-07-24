// https://cses.fi/problemset/task/3360

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
int n, k;
string grid[MAXN];
bitset<MAXN> row[26][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> grid[i];

    for (int ch = 0; ch < k; ++ch) {
        // Build bitsets for this character
        for (int i = 0; i < n; ++i) {
            row[ch][i].reset();
            for (int j = 0; j < n; ++j) {
                row[ch][i][j] = (grid[i][j] == ('A' + ch));
            }
        }
        bool found = false;
        for (int a = 0; a < n && !found; ++a) {
            for (int b = a + 1; b < n && !found; ++b) {
                if ((row[ch][a] & row[ch][b]).count() >= 2) {
                    found = true;
                }
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
}
