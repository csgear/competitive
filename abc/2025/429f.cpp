// https://atcoder.jp/contests/abc429/tasks/abc429_f

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200010;
const int INF = 0x3f3f3f3f;

struct Node {
    // stores the minimum number of steps to move from row i to row j within a range of columns.
    int f[4][4];
} tree[MAXN * 4];

int n, q;
char s[4][MAXN];

// Initialize leaf node at position x
void init(int p, int x) {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (s[i][x] == '#' || s[j][x] == '#' || (min(i, j) == 1 && max(i, j) == 3 && s[2][x] == '#')) {
                tree[p].f[i][j] = INF;
            } else {
                tree[p].f[i][j] = abs(i - j);
            }
        }
    }
}

void push_up(int p) {
    memset(tree[p].f, INF, sizeof(tree[p].f));
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                tree[p].f[i][j] = min(tree[p].f[i][j], tree[p * 2].f[i][k] + tree[p * 2 + 1].f[k][j] + 1);
            }
        }
    }
}

void build(int p, int l, int r) {
    if (l == r) {
        init(p, l);
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    push_up(p);
}

void update(int p, int idx, int l, int r) {
    if (l == r) {
        init(p, l);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(p * 2, idx, l, mid);
    } else {
        update(p * 2 + 1, idx, mid + 1, r);
    }
    push_up(p);
}

int main() {
    scanf("%d %s %s %s %d", &n, s[1] + 1, s[2] + 1, s[3] + 1, &q);

    build(1, 1, n);

    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (s[x][y] == '#') {
            s[x][y] = '.';
        } else {
            s[x][y] = '#';
        }
        update(1, y, 1, n);

        int ans = tree[1].f[1][3];
        if (ans >= INF) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}