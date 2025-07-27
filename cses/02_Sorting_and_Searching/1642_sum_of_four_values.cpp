// https://cses.fi/problemset/task/1642

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);  // (value, index)
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    map<int, vector<pair<int, int>>> pairSums;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = a[i].first + a[j].first;
            pairSums[sum].push_back({a[i].second, a[j].second});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = a[i].first + a[j].first;
            int complement = x - sum;

            if (pairSums.count(complement)) {
                for (auto& p : pairSums[complement]) {
                    if (p.first != a[i].second && p.first != a[j].second &&
                        p.second != a[i].second && p.second != a[j].second) {
                        cout << a[i].second << " " << a[j].second << " " << p.first << " "
                             << p.second << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}