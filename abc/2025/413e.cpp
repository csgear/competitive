// https://atcoder.jp/contests/abc413/tasks/abc413_e

#include <bits/stdc++.h>
using namespace std;

const int N = 270000;

int n, a[N];

void dfs(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    int lmin = *min_element(a + l, a + mid + 1);
    int rmin = *min_element(a + mid + 1, a + r + 1);
    if (lmin > rmin) {
        // Swap first half with second half
        int len = mid - l + 1;
        for (int i = 0; i < len; i++) {
            swap(a[l + i], a[mid + 1 + i]);
        }
    }
    dfs(l, mid);
    dfs(mid + 1, r);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= (1 << n); i++) {
            cin >> a[i];
        }
        dfs(1, (1 << n));
        for (int i = 1; i <= (1 << n); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}