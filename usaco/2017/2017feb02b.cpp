// https://usaco.org/index.php?page=viewproblem2&cpid=712
// USACO 2017 February Contest, Bronze
// Problem 2. Why Did the Cow Cross the Road II

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> pos(26, {-1, -1});
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (pos[s[i] - 'A'].first == -1) {
            pos[s[i] - 'A'].first = i;
        } else {
            pos[s[i] - 'A'].second = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            auto [x, y] = pos[i];
            auto [u, v] = pos[j];
            // u is between x and y, but v is not
            if ((x < u && u < y) != (x < v && v < y)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}