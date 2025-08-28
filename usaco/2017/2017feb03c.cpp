// https://usaco.org/index.php?cpid=713&page=viewproblem2
// USACO 2017 February Contest, Bronze
// Problem 3. Why Did the Cow Cross the Road III

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x, y] = cows[i];
        if (cur < x) {
            ans += x - cur;
            cur = x;
        }
        ans += y;
        cur += y;
    }
    cout << ans << endl;
    return 0;
}