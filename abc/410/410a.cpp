// https://atcoder.jp/contests/abc410/tasks/abc410_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k, ans = 0;
    cin >> k;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}