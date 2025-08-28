// https://usaco.org/index.php?page=viewproblem2&cpid=615
// USACO 2016 February Contest, Bronze
// Problem 1. Milk Pails

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, m;
    cin >> x >> y >> m;

    int ans = 0;
    for (int i = 0; i <= m / x; i++) {
        for (int j = 0; j <= m / y; j++) {
            if (i * x + j * y <= m) {
                ans = max(ans, i * x + j * y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}