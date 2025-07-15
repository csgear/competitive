// https://cses.fi/problemset/task/1748
// Method 1: dp[N] + O(N^2)
// Method 2: dp[N] with pair<int, int>
// Method 3: Fenwick Tree with O(N log N)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 200005;

int lowbit(int x) { return x & -x; }

long long tree[MAXN];

// Update: Goes UP to update all nodes that include this index in their range
// Query: Goes DOWN to collect all partial sums needed for the prefix sum
void update(int idx, long long val) {
    for (int i = idx; i < MAXN; i += lowbit(i)) {
        tree[i] = (tree[i] + val) % MOD;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        sum = (sum + tree[i]) % MOD;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    // coordinate compressing is not mandatory for this problem
    // but it helps to reduce the range of indices in BIT
    // b.erase(unique(b.begin(), b.end()), b.end());

    long long total = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

        // Sum of all BIT values from index 1 to pos-1
        // Total count of increasing subsequences ending at values smaller than a[i]
        long long count = query(pos - 1);
        count = (count + 1) % MOD;
        update(pos, count);

        total = (total + count) % MOD;
    }

    cout << total << endl;
    return 0;
}