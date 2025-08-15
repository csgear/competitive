// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const long long INF = 1e18;

vector<long long> arr;
long long tree[4 * MAXN];
int n;

void build(int p, int pl, int pr) {
    if (pl == pr) {
        tree[p] = arr[pl - 1];
        return;
    }
    int mid = (pl + pr) / 2;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
}

long long query_min(int p, int pl, int pr, int ql, int qr) {
    if (qr < pl || ql > pr) return INF;
    if (ql <= pl && pr <= qr) return tree[p];
    int mid = (pl + pr) / 2;
    return min(query_min(p << 1, pl, mid, ql, qr), query_min(p << 1 | 1, mid + 1, pr, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_min(1, 1, n, l, r) << '\n';
    }

    return 0;
}
