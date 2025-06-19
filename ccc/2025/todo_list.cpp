// https://dmoj.ca/problem/ccc25s5
// CCC '25 S5 - To-Do List

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e6 + 3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    // Store all tasks as {start_time, duration}
    multimap<long long, long long> tasks;
    // Min-heap for available tasks: {duration, start_time}
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>>
        available;

    long long ans = 0;
    long long time = 0;
    int finished = 0;

    for (int i = 0; i < q; ++i) {
        string op;
        long long s, t;
        cin >> op >> s >> t;
        s = (s + ans - 1 + mod) % mod;
        t = (t + ans) % mod;
        cout << s << ' ' << t << '\n';
        tasks.emplace(s, t);

        while (!tasks.empty() && tasks.begin()->first <= time) {
            available.emplace(tasks.begin()->second, tasks.begin()->first);
            tasks.erase(tasks.begin());
        }

        if (available.empty() && !tasks.empty()) {
            time = tasks.begin()->first;
            while (!tasks.empty() && tasks.begin()->first <= time) {
                available.emplace(tasks.begin()->second, tasks.begin()->first);
                tasks.erase(tasks.begin());
            }
        }

        // Now, schedule all available tasks
        while (!available.empty()) {
            auto [dur, st] = available.top();
            available.pop();
            time = max(time, st) + dur;
            finished++;

            // Add any new tasks that have become available
            while (!tasks.empty() && tasks.begin()->first <= time) {
                available.emplace(tasks.begin()->second, tasks.begin()->first);
                tasks.erase(tasks.begin());
            }
        }

        ans = time;
        cout << ans << '\n';
    }
    return 0;
}
