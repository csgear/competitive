// https://atcoder.jp/contests/abc411/tasks/abc411_e

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int mod = 998244353;

int qpow(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) {
            r = 1ll * r * a % mod;
        }
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return r;
}

int n, a[MAXN][7];
vector<int> S;
vector<int> ps[MAXN * 6];
int c[MAXN];
int inv[7];

int main() {
    for (int i = 1; i <= 6; i++) {
        inv[i] = qpow(i, mod - 2);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> a[i][j];
            S.push_back(a[i][j]);
        }
    }
    // 离散化处理
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            ps[lower_bound(S.begin(), S.end(), a[i][j]) - S.begin()].push_back(i);
        }
        c[i] = 6;
    }

    int now_p = 1, prev_p = 1;

    int ans = 0;
    // 对于每一个数，考察有多少个骰子 <= S[i]
    // 从大到小枚举
    for (int i = S.size() - 1; i >= 0; i--) {
        for (auto p : ps[i]) {
            now_p = 1ll * now_p * inv[c[p]] % mod;
            --c[p];
            now_p = 1ll * now_p * c[p] % mod;
        }
        int p = (prev_p - now_p + mod) % mod;
        ans = (ans + 1ll * p * S[i] % mod) % mod;
        prev_p = now_p;
    }
    cout << ans << endl;
    return 0;
}