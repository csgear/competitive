// https://atcoder.jp/contests/abc450/tasks/abc450_e
// E - Fibonacci String

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const MAXN = 10005;

int prex[MAXN][30], prey[MAXN][30];
ll fcnt[100][30];
ll fsum[100];
string x, y;

ll dfs(int n, ll l, ll r, int c) {
    if (n == 1) {
        return prex[r][c] - prex[l - 1][c];
    }
    if (n == 2) {
        return prey[r][c] - prey[l - 1][c];
    }
    if (l == 1 && r == fsum[n]) {
        return fcnt[n][c];
    }
    ll mid = fsum[n - 1];
    if (r <= mid) {
        return dfs(n - 1, l, r, c);
    } else if (l > mid) {
        return dfs(n - 2, l - mid, r - mid, c);
    } else {
        return dfs(n - 1, l, mid, c) + dfs(n - 2, 1, r - mid, c);
    }
}

void solve() {
    cin >> x >> y;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < 26; j++) {
            prex[i + 1][j] = prex[i][j];
        }
        prex[i + 1][x[i] - 'a']++;
    }
    for (int i = 0; i < y.size(); i++) {
        for (int j = 0; j < 26; j++) {
            prey[i + 1][j] = prey[i][j];
        }
        prey[i + 1][y[i] - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
        fcnt[1][j] = prex[x.size()][j];
        fcnt[2][j] = prey[y.size()][j];
    }
    int n = 2;
    fsum[1] = x.size();
    fsum[2] = y.size();
    while (true) {
        n++;
        if (fsum[n - 1] > (ll)1e18 - fsum[n - 2]) {
            fsum[n] = (ll)2e18;
            break;
        }
        fsum[n] = fsum[n - 1] + fsum[n - 2];
        if (fsum[n] > (ll)1e18) break;
        for (int j = 0; j < 26; j++) {
            fcnt[n][j] = fcnt[n - 1][j] + fcnt[n - 2][j];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        char c;
        ll l, r;
        cin >> l >> r >> c;
        cout << dfs(n, l, r, c - 'a') << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}