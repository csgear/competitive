// https://atcoder.jp/contests/abc423/tasks/abc423_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 5;

int a[MAXN], b[MAXN], c[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // leaving time + id
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ll current_time = 0;
    for (int i = 1; i <= n; i++) {
        while (k < c[i]) {
            auto [t, id] = pq.top();
            pq.pop();
            k += c[id];
            current_time = t;
        }
        current_time = max(current_time, (ll)a[i]);
        cout << current_time << endl;
        k -= c[i];
        pq.push({current_time + b[i], i});
    }
    return 0;
}