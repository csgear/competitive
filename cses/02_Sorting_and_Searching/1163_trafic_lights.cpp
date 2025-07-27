// https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    set<int> lights = {0, x};
    multiset<int> segments = {x};
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        auto it = lights.upper_bound(p);
        int right = *it;
        int left = *prev(it);
        segments.erase(segments.find(right - left));
        segments.insert(p - left);
        segments.insert(right - p);
        lights.insert(p);
        ans.push_back(*segments.rbegin());
    }
    for (int v : ans) cout << v << ' ';
    cout << '\n';
}