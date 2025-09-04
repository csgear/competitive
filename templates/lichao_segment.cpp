// https://www.luogu.com.cn/problem/P4254

#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

struct line {
    double k, b;
} p[N * 2];

int tr[N << 2];

double getY(int id, double x) { return p[id].k * x + p[id].b; }

void update(int p, int l, int r, int L, int R, int id) {
    if (L <= l && r <= R) {
        int mid = (l + r) >> 1;
        if (getY(id, mid) > getY(tr[p], mid)) swap(id, tr[p]);
        if (getY(id, l) > getY(tr[p], l)) update(p << 1, l, mid, L, R, id);
        if (getY(id, r) > getY(tr[p], r)) update(p << 1 | 1, mid + 1, r, L, R, id);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(p << 1, l, mid, L, R, id);
    if (R > mid) update(p << 1 | 1, mid + 1, r, L, R, id);
}

double query(int p, int pl, int pr, double x) {
    if (pl == pr) return getY(tr[p], x);
    int mid = (pl + pr) >> 1;
    if (x <= mid)
        return max(getY(tr[p], x), query(p << 1, pl, mid, x));
    else
        return max(getY(tr[p], x), query(p << 1 | 1, mid + 1, pr, x));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "Project") {
            double b, k;
            cin >> b >> k;
            p[i].k = k;
            p[i].b = b - k;
            update(1, 1, N, 1, N, i);
        } else if (s == "Query") {
            int x;
            cin >> x;
            double result = query(1, 1, N, x);
            cout << max(0, (int)(result / 100)) << "\n";
        }
    }

    return 0;
}