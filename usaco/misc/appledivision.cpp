#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> apples;
long long min_diff = LLONG_MAX;

void solve(int idx, long long first_group, long long remaining_group) {
    if (idx == n) {
        min_diff = min(min_diff, abs(first_group - remaining_group));
        return;
    }

    solve(idx + 1, first_group + apples[idx], remaining_group - apples[idx]);

    solve(idx + 1, first_group, remaining_group);
}

int main() {
    cin >> n;
    apples.resize(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        total_sum += apples[i];
    }

    solve(0, 0, total_sum);
    cout << min_diff << endl;

    return 0;
}