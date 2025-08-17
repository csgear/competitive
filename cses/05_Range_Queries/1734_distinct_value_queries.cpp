// https://cses.fi/problemset/model/1734/

#include <bits/stdc++.h>
using namespace std;

// Set block size equal to sqrt(N).
const int B = (int)sqrt(2e5);

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

    auto values = v;
    sort(values.begin(), values.end());

    for (int &x : v) {
        x = lower_bound(values.begin(), values.end(), x) - values.begin();
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].i = i;
    }

    sort(queries.begin(), queries.end(), [&](auto a, auto b) {
        if (a.l / B != b.l / B) {
            return a.l / B < b.l / B;
        }
        return a.r < b.r;
    });

    int res = 0;
    vector<int> cnt(n);
    vector<int> ans(q);

    auto add = [&](int i) {
        if (cnt[v[i]]++ == 0) {
            res++;
        }
    };

    auto remove = [&](int i) {
        if (--cnt[v[i]] == 0) {
            res--;
        }
    };

    int al = 0, ar = 0;
    add(0);

    for (auto [l, r, i] : queries) {
        // expand
        while (ar < r) add(++ar);
        while (al > l) add(--al);
        // shrink
        while (al < l) remove(al++);
        while (ar > r) remove(ar--);
        ans[i] = res;
    }

    for (int a : ans) {
        cout << a << endl;
    }
    return 0;
}