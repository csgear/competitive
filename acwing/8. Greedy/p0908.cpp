// https://www.acwing.com/problem/content/910/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e5 + 10;
pii a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](const pii& x, const pii& y) { return x.second < y.second; });

    int res = 0, end = -2e9;
    for (int i = 1; i <= n; i++) {
        if (a[i].first >= end) {
            res++;
            end = a[i].second;
        }
    }
    cout << res << endl;

    return 0;
}
