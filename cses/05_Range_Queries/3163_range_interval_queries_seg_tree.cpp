// https://cses.fi/problemset/task/3163
// Normal Segment Tree with sorted arrays in each node

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> tree[4 * N];
int a[N];
int n, q;

void build(int p, int pl, int pr) {
    if (pl == pr) {
        tree[p] = {a[pl]};
    } else {
        int mid = (pl + pr) >> 1;
        build(p << 1, pl, mid);
        build(p << 1 | 1, mid + 1, pr);

        // Merge sorted arrays from left and right children
        merge(tree[p << 1].begin(), tree[p << 1].end(), tree[p << 1 | 1].begin(),
              tree[p << 1 | 1].end(), back_inserter(tree[p]));
    }
}

int query(int L, int R, int p, int pl, int pr, int c, int d) {
    if (L > R) return 0;
    if (L == pl && R == pr) {
        // Count elements in range [c, d] using binary search
        return upper_bound(tree[p].begin(), tree[p].end(), d) -
               lower_bound(tree[p].begin(), tree[p].end(), c);
    }

    int mid = (pl + pr) >> 1;
    return query(L, min(R, mid), p << 1, pl, mid, c, d) +
           query(max(L, mid + 1), R, p << 1 | 1, mid + 1, pr, c, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int L, R, c, d;
        cin >> L >> R >> c >> d;
        cout << query(L, R, 1, 1, n, c, d) << '\n';
    }

    return 0;
}
/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1 << 18;

vector<int> tree[2 * N];

int query(int a, int b, int c, int d) {
    a += N;
    b += N;

    int count = 0;

    while (a <= b) {
        if (a % 2 == 1) {
            count += upper_bound(tree[a].begin(), tree[a].end(), d) -
                     lower_bound(tree[a].begin(), tree[a].end(), c);
            a++;
        }
        if (b % 2 == 0) {
            count += upper_bound(tree[b].begin(), tree[b].end(), d) -
                     lower_bound(tree[b].begin(), tree[b].end(), c);
            b--;
        }
        a /= 2;
        b /= 2;
    }

    return count;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree[N + i] = {x};
    }

    for (int i = N - 1; i >= 1; i--) {
        merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(),
              tree[2 * i + 1].end(), back_inserter(tree[i]));
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << query(a, b, c, d) << "\n";
    }
}
*/