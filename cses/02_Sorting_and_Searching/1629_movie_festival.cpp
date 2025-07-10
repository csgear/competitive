// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;

// similar to scheduling tasks with overlapping intervals
// similar to scheduling meetings with overlapping intervals
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    // sort by end time in ascending order
    // make sense if we pick the movie that ends first, we can pick more movies
    sort(movies.begin(), movies.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });

    int last_end = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= last_end) {
            last_end = movies[i].second;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}