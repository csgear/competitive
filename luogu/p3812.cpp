// https://www.luogu.com.cn/problem/P3812

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[55];
int n, k;

void linear_basis_gauss() {
    k = 1;
    for (int i = 62; i >= 0; i--) {
        for (int j = k; j <= n; j++) {
            if ((a[j] >> i) & 1) {
                swap(a[j], a[k]);
                break;
            }
        }
        if (((a[k] >> i) & 1) == 0) continue;
        for (int j = 1; j <= n; j++) {
            if (j != k && ((a[j] >> i) & 1)) {
                a[j] ^= a[k];
            }
        }
        k++;
        if (k > n) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    linear_basis_gauss();
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ans ^ a[i]);
    }
    cout << ans << "\n";
    return 0;
}