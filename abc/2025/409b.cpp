// https://atcoder.jp/contests/abc409/tasks/abc409_b

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n;
int a[MAXN];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, greater<int>());

    for (int x = 1; x <= n; x++) {
        if (a[x] < x) {
            cout << x - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
