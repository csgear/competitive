// https://atcoder.jp/contests/abc411/tasks/abc411_d

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
pair<int, string> rec[MAXN];
int m = 0;
int ver[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    memset(ver, 0, sizeof(ver));

    for (int i = 1; i <= q; i++) {
        int op, p;
        string s;
        cin >> op >> p;
        if (op == 1) {
            ver[p] = ver[0];
        } else if (op == 2) {
            m++;
            cin >> s;
            rec[m] = {ver[p], s};
            ver[p] = m;
        } else if (op == 3) {
            ver[0] = ver[p];
        }
    }
    int v = ver[0];
    string ans;
    while (v != 0) {
        string s = rec[v].second;
        reverse(s.begin(), s.end());
        ans += s;
        v = rec[v].first;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}