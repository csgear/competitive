// https://www.luogu.com.cn/problem/P5490

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 2e5 + 5;

struct Node {
    int len, cover, cnt;
} tree[N * 4];

struct Line {
    int x, y1, y2, flag;
    bool operator<(const Line& other) const { return x < other.x; }
};

vector<Line> lines;
vector<int> ys;

void pushup(int u, int pl, int pr) {
    if (tree[u].cnt > 0) {
        tree[u].cover = tree[u].len;
    } else if (pl == pr) {
        tree[u].cover = 0;
    } else {
        tree[u].cover = tree[u << 1].cover + tree[u << 1 | 1].cover;
    }
}

void build(int u, int pl, int pr) {
    if (pl < pr) {
        int mid = (pl + pr) >> 1;
        build(u << 1, pl, mid);
        build(u << 1 | 1, mid + 1, pr);
    }
    tree[u].len = ys[pr + 1] - ys[pl];
    tree[u].cnt = 0;
    tree[u].cover = 0;
}

void update(int L, int R, int u, int pl, int pr, int val) {
    if (L <= pl && pr <= R) {
        tree[u].cnt += val;
        pushup(u, pl, pr);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (L <= mid) update(L, R, u << 1, pl, mid, val);
    if (R > mid) update(L, R, u << 1 | 1, mid + 1, pr, val);
    pushup(u, pl, pr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    lines.clear();
    ys.clear();

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        lines.push_back({x1, y1, y2, 1});
        lines.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(lines.begin(), lines.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int m = ys.size();

    build(1, 0, m - 2);

    LL ans = 0;
    for (int i = 0; i < lines.size(); i++) {
        if (i > 0) {
            ans += (LL)tree[1].cover * (lines[i].x - lines[i - 1].x);
        }

        int y1 = lower_bound(ys.begin(), ys.end(), lines[i].y1) - ys.begin();
        int y2 = lower_bound(ys.begin(), ys.end(), lines[i].y2) - ys.begin();

        if (y1 < y2) {
            update(y1, y2 - 1, 1, 0, m - 2, lines[i].flag);
        }
    }

    cout << ans << endl;
    return 0;
}