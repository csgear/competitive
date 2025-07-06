// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << ans << endl;
    return 0;
}