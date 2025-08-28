// https://usaco.org/index.php?page=viewproblem2&cpid=617
// USACO 2016 February Contest, Bronze
// Problem 3. Load Balancing

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> cows(n);
    set<int> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        xs.insert(cows[i].first + 1);
        ys.insert(cows[i].second + 1);
    }

    // Sort cows by x
    sort(cows.begin(), cows.end());

    int ans = n;
    // For each possible vertical line
    for (int x : xs) {
        vector<int> left, right;
        for (auto& cow : cows) {
            if (cow.first < x)
                left.push_back(cow.second);
            else
                right.push_back(cow.second);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        // For each possible horizontal line
        int lsize = left.size(), rsize = right.size();
        int li = 0, ri = 0;
        for (int y : ys) {
            while (li < lsize && left[li] < y) li++;
            while (ri < rsize && right[ri] < y) ri++;
            int bl = li, br = ri;                  // below left/right
            int al = lsize - li, ar = rsize - ri;  // above left/right
            int mx = max({bl, br, al, ar});
            ans = min(ans, mx);
        }
    }
    cout << ans << endl;
    return 0;
}