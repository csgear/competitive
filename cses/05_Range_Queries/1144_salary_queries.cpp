// https://cses.fi/problemset/task/1144

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
int p[N];

ll tree[N * 4 << 2];

void point_update(int pos, ll val, int p_node, int pl, int pr) {
    if (pl == pr) {
        tree[p_node] += val;
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_update(pos, val, p_node << 1, pl, mid);
    else
        point_update(pos, val, p_node << 1 | 1, mid + 1, pr);
    tree[p_node] = tree[p_node << 1] + tree[p_node << 1 | 1];
}

ll range_query(int L, int R, int p_node, int pl, int pr) {
    if (L > R) return 0;
    if (L <= pl && pr <= R) {
        return tree[p_node];
    }
    int mid = (pl + pr) >> 1;
    ll res = 0;
    if (L <= mid) res += range_query(L, R, p_node << 1, pl, mid);
    if (R > mid) res += range_query(L, R, p_node << 1 | 1, mid + 1, pr);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<char> qt(q);
    vector<int> qa(q), qb(q);
    vector<int> coords;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        coords.push_back(p[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> qt[i] >> qa[i] >> qb[i];
        if (qt[i] == '!') {
            coords.push_back(qb[i]);
        } else {
            coords.push_back(qa[i]);
            coords.push_back(qb[i]);
        }
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto get_coord_a = [&](int val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
    };
    auto get_coord_b = [&](int val) {
        return upper_bound(coords.begin(), coords.end(), val) - coords.begin();
    };

    int max_coord = coords.size();

    for (int i = 1; i <= n; i++) {
        point_update(get_coord_a(p[i]), 1, 1, 1, max_coord);
    }

    for (int i = 0; i < q; i++) {
        if (qt[i] == '!') {
            int k = qa[i];
            int x = qb[i];
            point_update(get_coord_a(p[k]), -1, 1, 1, max_coord);
            p[k] = x;
            point_update(get_coord_a(p[k]), 1, 1, 1, max_coord);
        } else {
            int a = qa[i];
            int b = qb[i];
            cout << range_query(get_coord_a(a), get_coord_b(b), 1, 1, max_coord) << "\n";
        }
    }

    return 0;
}