// https://atcoder.jp/contests/abc425/tasks/abc425_a

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL sum = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i * i * i;
        } else {
            sum -= i * i * i;
        }
    }
    cout << sum << "\n";
    return 0;
}