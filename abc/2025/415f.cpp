// https://atcoder.jp/contests/abc415/tasks/abc415_f

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e5 + 5;
int asnm[MAXN << 2], ansl[MAXN << 2], ansr[MAXN << 2];
char s[MAXN];

void push_up(int p, int pl, int pr) {
    int mid = (pl + pr) >> 1;

    // Update ansl (longest prefix)
    ansl[p] = ansl[p << 1];
    if (ansl[p << 1] == (mid - pl + 1) && s[mid] == s[mid + 1]) ansl[p] += ansl[p << 1 | 1];

    // Update ansr (longest suffix)
    ansr[p] = ansr[p << 1 | 1];
    if (ansr[p << 1 | 1] == (pr - (mid + 1) + 1) && s[mid] == s[mid + 1]) ansr[p] += ansr[p << 1];

    // Update asnm (maximum segment)
    asnm[p] = max(asnm[p << 1], asnm[p << 1 | 1]);
    if (s[mid] == s[mid + 1]) asnm[p] = max(asnm[p], ansr[p << 1] + ansl[p << 1 | 1]);
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        asnm[p] = 1;
        ansl[p] = 1;
        ansr[p] = 1;
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p, pl, pr);
}

void point_set(int pos, char val, int p, int pl, int pr) {
    if (pl == pr) {
        s[pl] = val;
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        point_set(pos, val, p << 1, pl, mid);
    else
        point_set(pos, val, p << 1 | 1, mid + 1, pr);
    push_up(p, pl, pr);
}

int range_query(int L, int R, int p, int pl, int pr) {
    if (L > R) return 0;
    if (L <= pl && pr <= R) {
        return asnm[p];
    }
    int mid = (pl + pr) >> 1;
    int res1 = 0, res2 = 0;
    if (L <= mid) res1 = range_query(L, R, p << 1, pl, mid);
    if (R > mid) res2 = range_query(L, R, p << 1 | 1, mid + 1, pr);

    // Handle the case where the maximum segment crosses the middle
    int cross = 0;
    if (L <= mid && R > mid && s[mid] == s[mid + 1]) {
        int left_suffix = min(ansr[p << 1], mid - max(L, pl) + 1);
        int right_prefix = min(ansl[p << 1 | 1], min(R, pr) - (mid + 1) + 1);
        cross = left_suffix + right_prefix;
    }

    return max({res1, res2, cross});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Use cin instead of scanf for consistency
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            char x;
            cin >> i >> x;
            point_set(i, x, 1, 1, n);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << range_query(l, r, 1, 1, n) << '\n';
            // Make sure to flush the output
            cout.flush();
        }
    }
    return 0;
}