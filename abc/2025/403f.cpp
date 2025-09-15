// https://atcoder.jp/contests/abc403/tasks/abc403_f

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int N = 2005;
string f[N], g[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i == 1)
            f[i] = g[i] = "1";
        else if (i == 11)
            f[i] = g[i] = "11";
        else if (i == 111)
            f[i] = g[i] = "111";
        else if (i == 1111)
            f[i] = g[i] = "1111";
        else {
            f[i] = f[1] + '+' + f[i - 1];
            for (int a = 1; a + a <= i; a++) {
                int b = i - a;
                if (f[a].size() + 1 + f[b].size() < f[i].size()) {
                    f[i] = f[a] + '+' + f[b];
                }
                if (f[a].size() + 1 + g[b].size() < f[i].size()) {
                    f[i] = f[a] + '+' + g[b];
                }
                if (g[a].size() + 1 + f[b].size() < f[i].size()) {
                    f[i] = g[a] + '+' + f[b];
                }
                if (g[a].size() + 1 + g[b].size() < f[i].size()) {
                    f[i] = g[a] + '+' + g[b];
                }
            }
        }

        g[i] = "1*(" + f[i] + ")";
        for (int a = 2; a * a <= i; a++) {
            if (i % a == 0) {
                int b = i / a;
                if (f[a].size() + 5 + f[b].size() < g[i].size()) {
                    g[i] = "(" + f[a] + ")*(" + f[b] + ")";
                }
                if (f[a].size() + 3 + g[b].size() < g[i].size()) {
                    g[i] = "(" + f[a] + ")*" + g[b];
                }
                if (g[a].size() + 3 + f[b].size() < g[i].size()) {
                    g[i] = g[a] + "*(" + f[b] + ")";
                }
                if (g[a].size() + 1 + g[b].size() < g[i].size()) {
                    g[i] = g[a] + "*" + g[b];
                }
            }
        }
    }
    cout << (f[n].size() < g[n].size() ? f[n] : g[n]) << "\n";
    return 0;
}