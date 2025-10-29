// https://www.acwing.com/problem/content/245/

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int tr[N * 2];
int a[N], ans[N];
int n;

int lowbit(int x) { return x & -x; }

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        // tr[i] = lowbit(i);
        add(i, 1);
    }

    for (int i = n; i >= 1; i--) {
        int k = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (query(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        ans[i] = l;
        add(l, -1);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}