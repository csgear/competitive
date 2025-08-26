// https://www.luogu.com.cn/problem/P1856

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 2e5 + 5;

struct Node {
    int len, cover, cnt;
} tree[N * 4];

struct Line {
    int pos, start, end, flag;
    bool operator<(const Line& other) const {
        if (pos != other.pos) return pos < other.pos;
        return flag > other.flag;
    }
};

vector<Line> lines;
vector<int> coords;

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
    tree[u].len = coords[pr + 1] - coords[pl];
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

LL computePerimeter(vector<Line>& lines, vector<int>& coords) {
    sort(lines.begin(), lines.end());
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int m = coords.size();
    build(1, 0, m - 2);

    LL perimeter = 0;

    for (int i = 0; i < lines.size(); i++) {
        int prev_cover = tree[1].cover;

        int start = lower_bound(coords.begin(), coords.end(), lines[i].start) - coords.begin();
        int end = lower_bound(coords.begin(), coords.end(), lines[i].end) - coords.begin();

        if (start < end) {
            update(start, end - 1, 1, 0, m - 2, lines[i].flag);
        }

        perimeter += abs(tree[1].cover - prev_cover);
    }

    return perimeter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Line> vlines, hlines;
    vector<int> xs, ys;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        vlines.push_back({x1, y1, y2, 1});
        vlines.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);

        hlines.push_back({y1, x1, x2, 1});
        hlines.push_back({y2, x1, x2, -1});
        xs.push_back(x1);
        xs.push_back(x2);
    }

    lines = vlines;
    coords = ys;
    LL hperim = computePerimeter(lines, coords);

    lines = hlines;
    coords = xs;
    LL vperim = computePerimeter(lines, coords);

    cout << hperim + vperim << endl;
    return 0;
}