// https://www.luogu.com.cn/problem/P4570

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 1e3 + 5;
int n, k;
pair<LL, LL> a[MAXN];
LL b[MAXN];
LL ans;

bool insert(LL x) {
    for (int i = 62; i >= 0; i--) {
        if (((x >> i) & 1) == 0) continue;
        if (b[i] == 0) {
            b[i] = x;
            return true;
        }
        x ^= b[i];
    }

    return false;
}

void linear_basis_greed() {
    for (int i = 1; i <= n; i++) {
        if (insert(a[i].first)) {
            ans += a[i].second;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1,
         [](const pair<LL, LL>& x, const pair<LL, LL>& y) { return x.second > y.second; });
    linear_basis_greed();
    cout << ans << "\n";
    return 0;
}
