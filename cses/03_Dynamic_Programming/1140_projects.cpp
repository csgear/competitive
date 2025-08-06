// https://cses.fi/problemset/task/1140

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 2e5 + 5;

struct Project {
    int start, end, reward;
    bool operator<(const Project& other) const { return end < other.end; }
} projects[mxN];

ll dp[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects, projects + n);

    dp[0] = projects[0].reward;

    for (int i = 1; i < n; i++) {
        ll skip = dp[i - 1];

        ll take = projects[i].reward;

        auto it = upper_bound(projects, projects + i, projects[i].start,
                              [](int start_time, const Project& p) { return start_time <= p.end; });

        int latest = (it == projects) ? -1 : (it - projects - 1);
        if (latest != -1) {
            take += dp[latest];
        }

        dp[i] = max(skip, take);
    }

    cout << dp[n - 1] << "\n";

    return 0;
}