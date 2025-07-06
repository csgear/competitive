// https://cses.fi/problemset/task/3311

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<string> result(n, string(m, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char current = grid[i][j];
            char new_char = 'A';

            // Try to find a different character that doesn't conflict with neighbors
            for (char c = 'A'; c <= 'D'; c++) {
                if (c == current) continue;  // Must be different from original

                bool valid = true;

                // Check left neighbor
                if (j > 0 && result[i][j - 1] == c) valid = false;

                // Check top neighbor
                if (i > 0 && result[i - 1][j] == c) valid = false;

                // Check right neighbor (if already filled)
                if (j < m - 1 && result[i][j + 1] == c) valid = false;

                // Check bottom neighbor (if already filled)
                if (i < n - 1 && result[i + 1][j] == c) valid = false;

                if (valid) {
                    new_char = c;
                    break;
                }
            }

            result[i][j] = new_char;
        }
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}