// https://www.luogu.com.cn/problem/P5094

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 5;

int n;
pii a[N];
pii b[N];

ll merge(int l, int mid, int r) {
    int p1, p2;
    ll lsum = 0, rsum = 0, ans = 0;
    for (p1 = l; p1 <= mid; p1++) {
        rsum += a[p1].second;
    }

    // p1 starts from l-1 because:
    // 1. We want to count how many left elements have x-coordinate < current right element
    // 2. The while loop will increment p1 first, so starting at l-1 means first valid p1 will be l
    // 3. This way (p1 - l + 1) correctly counts the number of left elements processed
    for (p1 = l - 1, p2 = mid + 1; p2 <= r; p2++) {
        while (p1 + 1 <= mid && a[p1 + 1].second < a[p2].second) {
            p1++;
            lsum += a[p1].second;
            rsum -= a[p1].second;
        }
        ans += (1ll * (p1 - l + 1) * a[p2].second - lsum + rsum - 1ll * (mid - p1) * a[p2].second) *
               a[p2].first;
    }

    p1 = l, p2 = mid + 1;
    int i = l;
    while (p1 <= mid && p2 <= r) {
        if (a[p1].second <= a[p2].second)
            b[i++] = a[p1++];
        else
            b[i++] = a[p2++];
    }
    while (p1 <= mid) b[i++] = a[p1++];
    while (p2 <= r) b[i++] = a[p2++];
    for (i = l; i <= r; i++) a[i] = b[i];

    return ans;
}

ll cdq(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) / 2;
    return cdq(l, mid) + cdq(mid + 1, r) + merge(l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    ll result = cdq(1, n);
    cout << result << "\n";
    return 0;
}