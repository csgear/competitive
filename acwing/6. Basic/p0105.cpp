// https://www.acwing.com/problem/content/107/
// 105. 七夕祭

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100000 + 10;
ll row[N], col[N];

int n, m, t;

ll solve(int k, ll a[]) {
    ll total = 0;

    for (int i = 1; i <= k; i++) {
        total += a[i];
    }

    if (total % k != 0) return -1;

    ll avg = total / k;

    vector<ll> c(k);

    c[0] = 0;

    for (int i = 1; i < k; i++) {
        c[i] = c[i - 1] + a[i] - avg;
    }

    // find median
    nth_element(c.begin(), c.begin() + k / 2, c.end());

    ll median = c[k / 2];

    ll res = 0;
    for (int i = 0; i < k; i++) {
        res += abs(c[i] - median);
    }
    return res;
}

int main() {
    cin >> n >> m >> t;

    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        row[x]++;
        col[y]++;
    }

    ll r = solve(n, row);
    ll c = solve(m, col);

    if (c != -1 && r != -1)
        cout << "both " << r + c << endl;
    else if (r != -1)
        cout << "row " << r << endl;
    else if (c != -1)
        cout << "column " << c << endl;
    else
        cout << "impossible" << endl;

    return 0;
}
