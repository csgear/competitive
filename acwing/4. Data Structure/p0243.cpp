// https://www.acwing.com/problem/content/244/
// 2 BIT trees + difference array + prefix sum
// range add + range sum

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010, M = 100010;

int a[N];
ll tr1[N];
ll tr2[N];

int n, m;

int lowbit(int x) { return x & -x; }

void add(ll tr[], int x, ll c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

ll query(ll tr[], int x) {
    ll res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

ll prefix_sum(int x) { return query(tr1, x) * (x + 1) - query(tr2, x); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(tr1, i, a[i] - a[i - 1]);
        add(tr2, i, (ll)(a[i] - a[i - 1]) * i);
    }

    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << prefix_sum(r) - prefix_sum(l - 1) << "\n";
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            add(tr1, l, c);
            add(tr1, r + 1, -c);
            add(tr2, l, (ll)l * c);
            add(tr2, r + 1, (ll)(r + 1) * -c);
        }
    }

    return 0;
}