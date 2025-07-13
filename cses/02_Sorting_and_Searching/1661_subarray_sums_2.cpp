// https://cses.fi/problemset/task/1661
// Optimized solution using prefix sum + hash map

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long current_sum = 0;
    long long count = 0;
    map<long long, int> prefix_count;

    // base case, it's the key for the algorithm to work
    prefix_count[0] = 1;

    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        count += prefix_count[current_sum - x];
        prefix_count[current_sum]++;
    }

    cout << count << endl;
    return 0;
}
