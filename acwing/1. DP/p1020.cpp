// https://www.acwing.com/problem/content/1022/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

int a[N], b[N], w[N];
int f[N][N];

int m, n, k;

int main() {
    cin >> m >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }

    memset(f, 0x3f, sizeof f);

    f[0][0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = m; j >= 0; j--) {
            for (int l = n; l >= 0; l--) {
                f[j][l] = min(f[j][l], f[max(0, j - a[i])][max(0, l - b[i])] + w[i]);
            }
        }
    }

    cout << f[m][n] << endl;

    return 0;
}