// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Sort by duration (ascending)
    sort(tasks.begin(), tasks.end());

    long long current_time = 0;
    long long reward = 0;

    for (auto &task : tasks) {
        current_time += task.first;
        reward += task.second - current_time;
    }

    cout << reward << '\n';

    return 0;
}