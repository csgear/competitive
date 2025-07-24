// https://cses.fi/problemset/task/3419

#include <bits/stdc++.h>
using namespace std;

// Brute force solution with O(n^3) complexity
// MEX is a terminology in combinatorial game theory that refers to the minimum excludant,
// which is the smallest non-negative integer that is not present in a given set of integers.
int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // use set or boolean array to track used numbers
            // the number to the left and above won't be greater than 2*n
            vector<bool> used(2 * n, false);

            for (int k = 0; k < j; k++) {
                if (grid[i][k] < 2 * n) {
                    used[grid[i][k]] = true;
                }
            }

            for (int k = 0; k < i; k++) {
                if (grid[k][j] < 2 * n) {
                    used[grid[k][j]] = true;
                }
            }

            int mex = 0;
            while (mex < 2 * n && used[mex]) {
                mex++;
            }

            grid[i][j] = mex;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}