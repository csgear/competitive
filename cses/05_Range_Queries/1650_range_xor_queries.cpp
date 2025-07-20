// https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pxor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pxor[i] = pxor[i - 1] ^ a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (pxor[r] ^ pxor[l - 1]) << '\n';
    }
    return 0;
}