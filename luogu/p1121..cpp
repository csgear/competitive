// https://www.luogu.com.cn/problem/P1121

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 2e5 + 5;
int n, f[N], g[N], a[N], sum = 0, tot = 0;

int querySplit() {
    int res = -INF;
    // computes the maximum subarray sum ending at position i from left to right.
    // the classic Kadane's algorithm for maximum subarray sum.
    for (int i = 1; i <= n; i++) f[i] = max(f[i - 1], 0) + a[i];
    // computes the maximum subarray sum starting at position i from right to left.
    for (int i = n; i > 0; i--) g[i] = max(g[i + 1], 0) + a[i];
    // This converts f[i] from "maximum subarray ending at i" to "maximum subarray ending at or
    // before i".
    for (int i = 1; i <= n; i++) f[i] = max(f[i - 1], f[i]);
    // This converts g[i] from "maximum subarray starting at i" to "maximum subarray starting at
    // or after i".
    for (int i = n; i > 0; i--) g[i] = max(g[i + 1], g[i]);
    // enumerate the split point
    for (int i = 1; i < n; i++) res = max(res, f[i] + g[i + 1]);
    return res;
}

int main() {
    cin >> n;
    memset(f, -INF, sizeof(f));
    memset(g, -INF, sizeof(g));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        tot += a[i] > 0;
    }

    int t1 = querySplit();

    if (tot == 1) {
        cout << t1 << endl;
    } else {
        for (int i = 1; i <= n; i++) a[i] = -a[i];
        int t2 = sum + querySplit();
        // if t2 is 0, it means all numbers are negative, so return -INF
        if (!t2) t2 = -INF;
        cout << max(t1, t2) << endl;
    }
    return 0;
}
