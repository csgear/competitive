// https://www.acwing.com/problem/content/210/

#include <bits/stdc++.h>
using namespace std;

int mat[105][105];

int gauss(int n) {
    int rank = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = rank + 1; j <= n; j++) {
            if (mat[j][i] == 1) {
                t = j;
                break;
            }
        }

        if (t == 0) continue;

        rank++;

        if (t != rank) {
            for (int k = 1; k <= n + 1; k++) {
                swap(mat[rank][k], mat[t][k]);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (j != rank && mat[j][i] == 1) {
                for (int k = 1; k <= n + 1; k++) {
                    mat[j][k] ^= mat[rank][k];
                }
            }
        }
    }
    return rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        memset(mat, 0, sizeof(mat));

        for (int i = 1; i <= n; i++) {
            mat[i][i] = 1;
        }

        vector<int> start(n + 1), target(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> start[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> target[i];
            mat[i][n + 1] = start[i] ^ target[i];
        }

        int u, v;
        while (cin >> u >> v && (u || v)) {
            mat[v][u] = 1;
        }

        int rank = gauss(n);

        bool impossible = false;
        for (int i = rank + 1; i <= n; i++) {
            if (mat[i][n + 1] == 1) {
                impossible = true;
                break;
            }
        }

        if (impossible) {
            cout << "Oh,it's impossible~!!" << '\n';
        } else {
            int free_vars = n - rank;
            cout << (1 << free_vars) << '\n';
        }
    }

    return 0;
}