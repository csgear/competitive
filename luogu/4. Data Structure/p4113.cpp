// https://www.luogu.com.cn/problem/P4113
// P4113 [HEOI2012] 采花

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

using ll = long long;

int a[N], l1[N], l2[N], ans[N];

struct Query {
    int l, r, id;
    bool operator<(const Query& other) const { return r < other.r; }
} queries[N];

int n, c, m;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int size) : n(size), tree(size + 1, 0) {}

    int lowbit(int x) { return x & -x; }

    void add(int index, ll value) {
        assert(index > 0 && index <= n);
        for (; index <= n; index += lowbit(index)) {
            tree[index] += value;
        }
    }

    ll query(int index) {
        ll result = 0;
        for (; index > 0; index -= lowbit(index)) {
            result += tree[index];
        }
        return result;
    }

    ll range_query(int left, int right) { return query(right) - query(left - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    sort(queries + 1, queries + m + 1);

    BIT bit(n);

    int pos = 0;

    for (int i = 1; i <= m; i++) {
        int l = queries[i].l, r = queries[i].r, id = queries[i].id;
        while (pos < r) {
            pos++;
            int color = a[pos];

            // remove -1 if second last occurrence exists
            if (l2[color] > 0) {
                bit.add(l2[color], -1);
            }

            // add +1 if last occurrence exists
            if (l1[color] > 0) {
                bit.add(l1[color], 1);
            }

            l2[color] = l1[color];
            l1[color] = pos;
        }
        ans[id] = bit.range_query(l, r);
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}