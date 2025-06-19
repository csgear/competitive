// https://www.luogu.com.cn/problem/P4549
// P4549 【模板】裴蜀定理

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = gcd(abs(a[i]), ans);
    }
    cout << ans << endl;
}