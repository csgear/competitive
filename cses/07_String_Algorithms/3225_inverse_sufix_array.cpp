// https://cses.fi/problemset/task/3225

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int p[MAXN], inv[MAXN], n;
char tree[MAXN << 2];

void update(int node, int pl, int pr, int pos, char val) {
    if (pl == pr) {
        tree[node] = val;
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        update(node << 1, pl, mid, pos, val);
    else
        update(node << 1 | 1, mid + 1, pr, pos, val);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

char query(int node, int pl, int pr, int l, int r) {
    if (l > r) return 0;
    if (l <= pl && pr <= r) return tree[node];
    int mid = (pl + pr) >> 1;
    char res = 0;
    if (l <= mid) res = max(res, query(node << 1, pl, mid, l, r));
    if (r > mid) res = max(res, query(node << 1 | 1, mid + 1, pr, l, r));
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;  // Convert to 0-indexed
    }

    // Check if suffix array is valid permutation
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (p[i] < 0 || p[i] >= n || used[p[i]]) {
            cout << -1 << endl;
            return 0;
        }
        used[p[i]] = true;
    }

    // Build inverse suffix array
    for (int i = 0; i < n; i++) {
        inv[p[i]] = i;
    }

    string s(n, 'a');
    char c = 'a' - 1;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            c++;
        } else if (p[i] == n - 1) {
            c++;
        } else {
            // Check if we need to increment c
            int idx = inv[p[i] + 1];
            if (idx < n - 1 && query(1, 0, n - 1, idx + 1, n - 1) == c) {
                c++;
            }
        }

        if (c > 'z') {
            cout << -1 << endl;
            return 0;
        }

        s[p[i]] = c;

        // Update segment tree if p[i] < n-1
        if (p[i] < n - 1) {
            update(1, 0, n - 1, inv[p[i] + 1], c);
        }
    }

    cout << s << endl;
    return 0;
}