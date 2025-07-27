// https://cses.fi/problemset/task/2428
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll at_most_k(const vector<int>& a, int k) {
    int n = a.size();
    vector<int> freq(*max_element(a.begin(), a.end()) + 1, 0);
    ll res = 0;
    for (int l = 0, r = 0, cnt = 0; r < n; ++r) {
        if (++freq[a[r]] == 1) cnt++;
        while (cnt > k) {
            if (--freq[a[l]] == 0) cnt--;
            l++;
        }
        res += r - l + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Coordinate compression
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    ll ans = at_most_k(a, k);
    cout << ans << '\n';

    return 0;
}