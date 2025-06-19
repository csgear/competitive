// https://usaco.org/index.php?page=viewproblem2&cpid=835

// USACO 2018 US Open Contest, Silver
// Problem 2. Lemonade Line

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= ans) {
            ans++;
        }
    }
    cout << ans << endl;
}