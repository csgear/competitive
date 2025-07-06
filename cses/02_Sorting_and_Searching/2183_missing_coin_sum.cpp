// https://cses.fi/problemset/task/2183

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
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > ans + 1) {
            break;
        }
        ans += a[i];
    }
    cout << ans + 1 << endl;
    return 0;
}