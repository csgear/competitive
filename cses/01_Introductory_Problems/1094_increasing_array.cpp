// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < prev && prev != 0) {
            ans += prev - x;
        } else {
            prev = x;
        }
    }
    cout << ans << endl;
    return 0;
}