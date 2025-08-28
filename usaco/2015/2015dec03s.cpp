// https://usaco.org/index.php?page=viewproblem2&cpid=572

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int prefix[N][4];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int id;
        cin >> id;
        for (int j = 1; j <= 3; j++) {
            prefix[i][j] = prefix[i - 1][j];
        }
        prefix[i][id]++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        for (int i = 1; i <= 3; i++) {
            cout << prefix[r][i] - prefix[l - 1][i] << " \n"[i == 3];
        }
    }
    return 0;
}