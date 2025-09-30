// https://atcoder.jp/contests/abc425/tasks/abc425_b

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int a[15];
bool vis[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) continue;
        if (vis[a[i]]) {
            cout << "No\n";
            return 0;
        }
        vis[a[i]] = true;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    a[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
        cout << a[i] << (i == n ? "\n" : " ");
    }

    return 0;
}