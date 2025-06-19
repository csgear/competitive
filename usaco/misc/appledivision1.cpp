#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> apples(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        total_sum += apples[i];
    }

    long long min_diff = LLONG_MAX;

    // Iterate over all possible subsets (bitmasks)
    for (int mask = 0; mask < (1 << n); mask++) {
        long long first_group = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                first_group += apples[i];
            }
        }
        long long remaining_group = total_sum - first_group;
        min_diff = min(min_diff, abs(first_group - remaining_group));
    }

    cout << min_diff << endl;

    return 0;
}