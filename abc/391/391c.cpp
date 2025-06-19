// https://atcoder.jp/contests/abc391/tasks/abc391_c

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int p[MAXN], s[MAXN];
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int op, x, y;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            s[p[x]] -= 1;
            if (s[p[x]] == 1) cnt -= 1;
            p[x] = y;
            s[p[x]] += 1;
            if (s[p[x]] == 2) cnt += 1;
        } else if (op == 2) {
            cout << cnt << endl;
        }
    }
    return 0;
}