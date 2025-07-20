// https://cses.fi/problemset/task/3360

#include <bits/stdc++.h>
using namespace std;

// TLE
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Precompute positions for all characters at once
    vector<vector<pair<int, int>>> positions(26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
                positions[a[i][j] - 'A'].push_back({i, j});
            }
        }
    }

    // Loop through first k uppercase characters
    for (int i = 0; i < k; i++) {
        char c = 'A' + i;
        auto& pos = positions[i];
        bool found = false;

        if (pos.size() < 4) {
            cout << "NO\n";
            continue;
        }

        // Check pairs more efficiently with early termination
        for (int x = 0; x < pos.size(); x++) {
            for (int y = x + 1; y < pos.size(); y++) {
                auto [x1, y1] = pos[x];
                auto [x2, y2] = pos[y];
                if (x1 != x2 && y1 != y2) {
                    if (a[x1][y2] == c && a[x2][y1] == c) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
