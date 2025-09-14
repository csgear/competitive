// https://atcoder.jp/contests/abc403/tasks/abc403_e

#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;
const ull BASE = 51971;
const int Q = 2e5 + 5;
string s[Q];
set<ull> X;
set<pair<ull, int>> Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, ans = 0;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t >> s[i];
        if (t == 2) {
            ull hy = 0;
            bool flag = true;
            for (int j = 0; j < (int)s[i].size(); j++) {
                hy = hy * BASE + (s[i][j] - 'a' + 1);
                if (X.count(hy)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
                hy = 0;
                for (int j = 0; j < (int)s[i].size(); j++) {
                    hy = hy * BASE + (s[i][j] - 'a' + 1);
                    Y.insert({hy, i});
                }
            }
        } else if (t == 1) {
            ull hx = 0;
            for (int j = 0; j < (int)s[i].size(); j++) {
                hx = hx * BASE + (s[i][j] - 'a' + 1);
            }
            X.insert(hx);

            while (true) {
                auto it = Y.lower_bound({hx, 0});
                if (it != Y.end() && it->first == hx) {
                    int id = it->second;
                    ans--;
                    ull hy = 0;
                    for (int j = 0; j < (int)s[id].size(); j++) {
                        hy = hy * BASE + (s[id][j] - 'a' + 1);
                        Y.erase({hy, id});
                    }
                } else {
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}