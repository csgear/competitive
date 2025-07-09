// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;
        events.push_back({arrival, 1});
        events.push_back({departure, -1});
    }

    sort(events.begin(), events.end());

    int current_customers = 0;
    int max_customers = 0;

    for (const auto& event : events) {
        current_customers += event.second;
        max_customers = max(max_customers, current_customers);
    }

    cout << max_customers << endl;

    return 0;
}