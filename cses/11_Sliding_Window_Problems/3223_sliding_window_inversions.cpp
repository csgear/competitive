// https://cses.fi/problemset/task/3223

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N];
int tree[2 * N];

int lowbit(int x) { return x & -x; }

void update(int x, int val) {
    for (; x <= n; x += lowbit(x)) {
        tree[x] += val;
    }
}

int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
        res += tree[x];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> vals(a + 1, a + n + 1);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    }

    vector<long long> ans;
    long long inv_count = 0;

    for (int i = 1; i <= k; i++) {
        inv_count += query(n) - query(a[i]);
        update(a[i], 1);
    }
    ans.push_back(inv_count);

    for (int i = k + 1; i <= n; i++) {
        update(a[i - k], -1);
        inv_count -= query(a[i - k] - 1);

        inv_count += query(n) - query(a[i]);
        update(a[i], 1);

        ans.push_back(inv_count);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
    }
    cout << '\n';

    return 0;
}