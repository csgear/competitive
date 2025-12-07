// https://www.acwing.com/problem/content/106/
// 104. 货仓选址

#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int ans = 0;

    for (int i = 0; i < n; i++) ans += abs(a[i] - a[n / 2]);

    cout << ans << endl;

    return 0;
}
