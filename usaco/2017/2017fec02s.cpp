// https://usaco.org/index.php?page=viewproblem2&cpid=715
// USACO 2017 February Contest, Silver
// Problem 2. Why Did the Cow Cross the Road II

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> blocked(n + 1, 0);
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        blocked[x] = 1;
    }
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + blocked[i];
    }
    int result = INT_MAX;
    for (int i = k; i <= n; i++) {
        result = min(result, prefix[i] - prefix[i - k]);
    }
    cout << result << "\n";
    return 0;
}