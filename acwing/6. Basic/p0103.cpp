// https://www.acwing.com/problem/content//105/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

unordered_map<int, int> cnt;
int b[N], c[N];
tuple<int, int, int> a[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }

    cin >> m;

    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];

    for (int i = 1; i <= m; i++) {
        a[i] = {cnt[b[i]], cnt[c[i]], i};
    }

    sort(a + 1, a + m + 1, greater<tuple<int, int, int>>());

    cout << get<2>(a[1]) << endl;

    return 0;
}