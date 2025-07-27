// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies[i] = {end, start};
    }
    sort(movies.begin(), movies.end());
    multiset<int> end_times;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int start = movies[i].second;
        int end = movies[i].first;
        auto it = end_times.upper_bound(start);
        if (it != end_times.begin()) {
            --it;
            end_times.erase(it);
            end_times.insert(end);
            ans++;
        } else if ((int)end_times.size() < k) {
            end_times.insert(end);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}