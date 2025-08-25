// https://atcoder.jp/contests/abc420/tasks/abc420_e

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;
int color[N], cnt[N], fa[N];

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            merge(x, y);
        } else if (op == 2) {
            cin >> x;
            int fx = find(x);
            cnt[fx] -= color[x];
            color[x] ^= 1;
            cnt[fx] += color[x];
        } else if (op == 3) {
            cin >> x;
            if (cnt[find(x)] == 0) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}