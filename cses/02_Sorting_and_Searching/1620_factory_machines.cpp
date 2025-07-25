// https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>
using namespace std;

bool canProduce(const vector<int>& times, long long time, int t) {
    long long total = 0;
    for (int machine_time : times) {
        total += time / machine_time;
        if (total >= t) return true;
    }
    return total >= t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    long long left = 1;
    long long right = (long long)times[0] * t;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canProduce(times, mid, t)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
