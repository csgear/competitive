// https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], dp[N];

void dp_solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

// The algorithm maintains a vector<int> lis that represents the smallest possible ending values for
// increasing subsequences of different lengths. Here's how it works    :
// 1. For each element a[i], it finds the first element in lis that is greater than or equal to a[i]
// 2. If no such element is found, it means a[i] is larger than all elements in lis, so it extends
// the sequence by adding a[i]
// 3. If such an element is found, it replaces the first element in lis that is greater than or
// equal to a[i] with a[i]
// 4. The size of lis at the end of the algorithm is the length of the longest increasing
// subsequence
void solve() {
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        // Find the first element >= a[i] in lis
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        int pos = it - lis.begin();

        if (it == lis.end()) {
            // a[i] is larger than all elements, extend the sequence
            lis.push_back(a[i]);
            indices.push_back(i);
        } else {
            // Replace the first element >= a[i] with a[i]
            *it = a[i];
            indices[pos] = i;
        }
    }
    cout << lis.size() << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}