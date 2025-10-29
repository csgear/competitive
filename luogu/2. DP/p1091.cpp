// https://www.luogu.com.cn/problem/P1091

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e2 + 10;

int n, h[N];

int f1[N], f2[N];

void lis_dp() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (h[j] < h[i]) {
                f1[i] = max(f1[i], f1[j] + 1);
            }
        }
    }
}

void lds_dp() {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (h[j] < h[i]) {
                f2[i] = max(f2[i], f2[j] + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        f1[i] = f2[i] = 1;
    }
    lis_dp();
    lds_dp();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f1[i] + f2[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}