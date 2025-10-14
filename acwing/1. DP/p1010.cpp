// https://www.acwing.com/problem/content/1012/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int a[N], f[N], p[N];

int main() {
    int n = 1;
    while (cin >> a[n]) n++;

    n--;

    int res = 0;

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] <= a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }

    cout << res << endl;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int k = 1;
        while (k <= cnt && p[k] < a[i]) k++;
        if (k > cnt) cnt++;
        p[k] = a[i];
    }

    cout << cnt << endl;

    return 0;
}
