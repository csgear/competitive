// https://www.luogu.com.cn/problem/P3810
// P3810 【模板】三维偏序（陌上花开）

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXK = 2e5 + 5;

struct Point {
    int idx, a, b, c;
};

Point arr[MAXN];
int tree[MAXK];
int f[MAXN];
int ans[MAXN];
int n, k;

int lowbit(int x) { return x & (-x); }

void update(int idx, int val) {
    while (idx <= k) {
        tree[idx] += val;
        idx += lowbit(idx);
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

void prepare() {
    sort(arr + 1, arr + n + 1,
         [](const Point& a, const Point& b) { return tie(a.a, a.b, a.c) < tie(b.a, b.b, b.c); });

    for (int l = 1, r = 1; l <= n; l = r + 1) {
        while (r + 1 <= n &&
               tie(arr[r + 1].a, arr[r + 1].b, arr[r + 1].c) == tie(arr[l].a, arr[l].b, arr[l].c)) {
            r++;
        }

        for (int i = l; i <= r; i++) {
            f[arr[i].idx] = r - i;
        }
    }
}

void merge(int l, int m, int r) {
    int p1, p2;
    for (p1 = l - 1, p2 = m + 1; p2 <= r; p2++) {
        while (p1 + 1 <= m && arr[p1 + 1].b <= arr[p2].b) {
            p1++;
            update(arr[p1].c, 1);
        }
        f[arr[p2].idx] += query(arr[p2].c);
    }
    for (int i = l; i <= p1; i++) {
        update(arr[i].c, -1);
    }
    sort(arr + l, arr + r + 1,
         [](const Point& a, const Point& b) { return tie(a.b, a.c) < tie(b.b, b.c); });
}

void cdq(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].idx = i;
    }
    prepare();
    cdq(1, n);
    for (int i = 1; i <= n; i++) {
        ans[f[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}