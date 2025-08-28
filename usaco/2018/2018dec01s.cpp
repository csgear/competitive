// https://usaco.org/index.php?page=viewproblem2&cpid=858
// USACO 2018 December Contest, Silver
// Problem 1. Convention

#include <bits/stdc++.h>
using namespace std;

bool search(int max_wait, const vector<int>& cows, int m, int c) {
    int buses = 1, first = 0;
    int n = cows.size();
    for (int i = 1; i < n; ++i) {
        if (cows[i] - cows[first] > max_wait || i - first + 1 > c) {
            buses++;
            first = i;
        }
    }
    return buses <= m;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    int left = 0, right = cows[n - 1] - cows[0], ans = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (search(mid, cows, m, c)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}