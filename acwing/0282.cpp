// https://www.acwing.com/problem/content/284/

#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int a[N], pre[N];
int f[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) f[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}