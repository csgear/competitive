// https://www.acwing.com/problem/content/1014/
// 2D LIS problem on pairs (height, weight)
// Sort by one dimension, find LIS on the other
// State: f[i] = length of LIS ending at pair i

#include <bits/stdc++.h>
using namespace std;
const int N = 5010;

pair<int, int> a[N];
int f[N];

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i].second > a[j].second) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}