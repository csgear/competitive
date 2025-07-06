// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // use selection algorithm to find the median
    // nth_element(a.begin(), a.begin() + n / 2, a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - a[n / 2]);
    }
    cout << ans << endl;
    return 0;
}