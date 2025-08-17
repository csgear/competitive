// https://atcoder.jp/contests/abc404/tasks/abc404_d

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10 + 5;
const int MAXM = 100 + 5;

int n, m;
long long c[MAXN];
int a[MAXM][MAXN], k[MAXM];
int pw[MAXN], v[MAXN];

long long ans = 1e18;

int main() {
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 3;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j];
        }
    }
    for (int S = 0; S < pw[n]; S++) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            v[i] = (S / pw[i - 1]) % 3;
            sum += v[i] * c[i];
        }
        bool flag = false;
        for (int i = 1; i <= m; i++) {
            int cnt = 0;
            for (int j = 1; j <= k[i]; j++) {
                cnt += v[a[i][j]];
            }
            if (cnt < 2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
