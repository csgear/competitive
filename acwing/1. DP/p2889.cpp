// https://www.acwing.com/problem/content/2892/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 5010, INF = 0x3f3f3f3f;

int pre[N];
int f[N][N];
int p[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    memset(f, 0x3f, sizeof f);

    for (int i = 1; i <= n; i++) {
        p[i][i] = i;
        f[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = p[l][r - 1]; k <= p[l + 1][r]; k++) {
                int t = f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1];
                if (f[l][r] > t) {
                    f[l][r] = t;
                    p[l][r] = k;
                }
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}