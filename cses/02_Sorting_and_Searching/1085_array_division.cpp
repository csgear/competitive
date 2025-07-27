// https://cses.fi/problemset/task/1085
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool can_divide(const vector<int>& a, int k, ll max_sum) {
    int cnt = 1;
    ll curr = 0;
    for (int x : a) {
        if (curr + x > max_sum) {
            cnt++;
            curr = 0;
        }
        curr += x;
    }
    return cnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll left = *max_element(a.begin(), a.end());
    ll right = accumulate(a.begin(), a.end(), 0LL);
    ll ans = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (can_divide(a, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}