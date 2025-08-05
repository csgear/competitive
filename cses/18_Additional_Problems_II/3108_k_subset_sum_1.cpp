// https://cses.fi/problemset/task/3108

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    set<pair<ll, int>> visited;

    pq.push({0, -1});
    visited.insert({0, -1});

    for (int i = 0; i < n; i++) {
        pq.push({a[i], i});
        visited.insert({a[i], i});
    }

    for (int count = 0; count < k; count++) {
        auto [sum, idx] = pq.top();
        pq.pop();

        cout << sum;
        if (count < k - 1) cout << " ";

        for (int i = idx + 1; i < n; i++) {
            ll new_sum = sum + a[i];
            if (visited.find({new_sum, i}) == visited.end()) {
                pq.push({new_sum, i});
                visited.insert({new_sum, i});
            }
        }
    }

    cout << endl;
    return 0;
}