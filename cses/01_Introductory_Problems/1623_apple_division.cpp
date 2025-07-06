// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += weights[i];
    }

    long long min_diff = LLONG_MAX;

    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1_sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1_sum += weights[i];
            }
        }

        long long group2_sum = total_sum - group1_sum;

        long long diff = abs(group1_sum - group2_sum);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}