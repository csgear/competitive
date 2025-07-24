// https://cses.fi/problemset/model/1734/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int tree[N << 2];

void push_up(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

void point_set(int pos, int val, int p, int pl, int pr) {
    if (pl == pr) {
        tree[p] = val;
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_set(pos, val, p << 1, pl, mid);
    else
        point_set(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p);
}

int range_sum_query(int L, int R, int p, int pl, int pr) {
    if (L > R) return 0;
    if (L <= pl && pr <= R) {
        return tree[p];
    }
    int mid = (pl + pr) >> 1;
    int res = 0;
    if (L <= mid) res += range_sum_query(L, R, p << 1, pl, mid);
    if (R > mid) res += range_sum_query(L, R, p << 1 | 1, mid + 1, pr);
    return res;
}

struct Query {
    int l, r, i;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    map<int, vector<int>> occurrences;
    for (int i = n - 1; i >= 0; --i) {
        occurrences[v[i]].push_back(i);
    }

    for (auto &[vval, l] : occurrences) {
        point_set(l.back() + 1, 1, 1, 1, n);
        l.pop_back();
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].i = i;
    }

    sort(queries.begin(), queries.end(), [&](auto a, auto b) { return a.l < b.l; });

    vector<int> answer(q);

    for (int i = 0, j = 0; i < n; ++i) {
        while (j < q && queries[j].l == i) {
            answer[queries[j].i] = range_sum_query(i + 1, queries[j].r + 1, 1, 1, n);
            ++j;
        }
        if (!occurrences[v[i]].empty()) {
            point_set(occurrences[v[i]].back() + 1, 1, 1, 1, n);
            occurrences[v[i]].pop_back();
        }
    }

    for (int a : answer) {
        cout << a << endl;
    }
    return 0;
}