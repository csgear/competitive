// https://usaco.org/index.php?page=viewproblem2&cpid=1204
// USACO 2022 February Contest, Bronze
// Problem 2. Photoshoot 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> a, b, p;
    int maxn = 0, ans = 0;
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    p.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        p[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = pos[a[i]];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] > maxn)
            maxn = a[i];
        else
            ++ans;
    }
    cout << ans << endl;
    return 0;
}