// https://atcoder.jp/contests/abc425/tasks/abc425_e

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5010;

ll C[N][N];
ll T, mod;

void init() {
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> mod;
    init();

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            ans = ans * C[sum][a[i]] % mod;
            sum -= a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}