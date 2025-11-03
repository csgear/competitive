// https://www.acwing.com/problem/content/248/
// BIT + difference array + sum
// range add + point query

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010, M = 100010;

int a[N];
ll tree[N];

int n, m;

int lowbit(int x) { return x & -x; }

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[i] += c;
    }
}

ll query(int x) {
    ll res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }

    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int x;
            cin >> x;
            cout << query(x) << "\n";
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            add(l, c);
            add(r + 1, -c);
        }
    }

    return 0;
}