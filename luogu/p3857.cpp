// https://www.luogu.com.cn/problem/P3857

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 100;
LL a[MAXN], b[MAXN];
int n, m, k = 0;

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
        if (insert(a[i])) {
            k++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        LL val = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'O') {
                val |= 1LL << j;
            }
        }
        a[i] = val;
    }
    linear_basis_greed();
    cout << (1LL << k) % 2008 << "\n";
    return 0;
}
