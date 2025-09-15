// https://usaco.org/index.php?page=viewproblem2&cpid=963
// USACO 2019 December Contest, Bronze
// Problem 1. Cow Gymnastics

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                mp[make_pair(a[i][j], a[i][l])]++;
            }
        }
    }

    int ans = 0;
    for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == k) ans++;
    }

    cout << ans << endl;
}