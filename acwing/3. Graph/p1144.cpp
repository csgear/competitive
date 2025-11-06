// https://www.acwing.com/problem/content/1146/
// 1144. 连接格点

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int MAXN = N * N;

int fa[MAXN];
int m, n;  // m rows, n columns

inline int id(int x, int y) { return x * n + y; }

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;  // m rows, n columns

    int total = m * n;
    for (int i = 0; i < total; ++i) {
        fa[i] = i;
    }

    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        --x1, --y1, --x2, --y2;
        int u = id(x1, y1);
        int v = id(x2, y2);
        fa[find(u)] = find(v);
    }

    int res = 0;

    for (int c = 0; c < n; ++c) {          // each column
        for (int r = 0; r < m - 1; ++r) {  // from row 0 to m-2
            int u = id(r, c);
            int v = id(r + 1, c);
            if (find(u) != find(v)) {
                fa[find(u)] = find(v);
                res += 1;
            }
        }
    }

    for (int c = 0; c < n - 1; ++c) {
        int u = id(0, c);
        int v = id(0, c + 1);
        if (find(u) != find(v)) {
            fa[find(u)] = find(v);
            res += 2;
        }
    }

    cout << res << '\n';
    return 0;
}