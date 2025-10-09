// https://atcoder.jp/contests/abc422/tasks/abc422_d

#include <bits/stdc++.h>
using namespace std;

int n, k, a[10000010];
int mi = 0;

int f(int l, int r, int num) {
    if (l == r) {
        a[l] = num;
        return num;
    }
    int m = (l + r) / 2;
    int tot1 = f(l, m, num / 2);
    int tot2 = f(m + 1, r, num - num / 2);
    mi = max(mi, abs(tot1 - tot2));
    return tot1 + tot2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    f(1, pow(2, n), k);
    cout << mi << '\n';
    for (int i = 1; i <= pow(2, n); i++) cout << a[i] << " ";
    return 0;
}