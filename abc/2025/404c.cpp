// https://atcoder.jp/contests/abc404/tasks/abc404_c

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int f[MAX_N], deg[MAX_N], n, m;

void build() {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x != y) {
        f[x] = y;
    }
}

int main() {
    istream::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    build();

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
        ++deg[u];
        ++deg[v];
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
