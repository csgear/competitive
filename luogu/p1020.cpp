// https://www.luogu.com.cn/problem/P1020

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], c[MAXN];

int ans = 0;

int main() {
    int n = 1;
    int m = 0;

    while (true) {
        if (!(cin >> a[n])) break;
        n++;
    }

    n = n - 1;

    for (int i = 1; i <= n; i++) {
        b[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) {
                b[i] = max(b[i], b[j] + 1);
            }
        }
        ans = max(ans, b[i]);
        int s = 0;
        for (int j = 1; j <= m; j++) {
            if (c[j] >= a[i]) {
                c[j] = a[i];
                s = 1;
                break;
            }
        }
        if (s == 0) {
            m++;
            c[m] = a[i];
        }
    }

    cout << ans << endl;
    cout << m << endl;

    return 0;
}