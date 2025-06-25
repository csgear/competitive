// https://www.luogu.com.cn/problem/P1025

#include <bits/stdc++.h>
using namespace std;
int ans, n, k;

void dfs(int start, int step, int sum) {
    if (step == k) {
        if (sum == n) {
            ans++;
        }
        return;
    }
    for (int i = start; i + sum <= n; i++) {
        dfs(i, step + 1, i + sum);
    }
}
int main() {
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}