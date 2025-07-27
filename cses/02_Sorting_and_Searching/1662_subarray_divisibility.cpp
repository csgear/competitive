// https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> count(n, 0);
    count[0] = 1;

    long long prefix_sum = 0;
    long long result = 0;

    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + a[i] % n + n) % n;

        result += count[prefix_sum];

        count[prefix_sum]++;
    }

    cout << result << "\n";
    return 0;
}