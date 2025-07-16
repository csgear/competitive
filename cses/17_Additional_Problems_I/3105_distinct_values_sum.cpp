// https://cses.fi/problemset/task/3150

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> last;
    long long ans = 0;

    // The number of subarrays where a[i] appears as the FIRST occurrence of its value.
    // left end (lastIndex + 1... i) and right end (i... n)
    // total = (i - lastIndex) * (n - i + 1)
    for (int i = 1; i <= n; i++) {
        int lastIndex = last[a[i]];
        ans += (long long)(i - lastIndex) * (n - i + 1);
        last[a[i]] = i;
    }

    cout << ans << endl;
    return 0;
}