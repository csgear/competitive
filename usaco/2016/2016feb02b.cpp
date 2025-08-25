// Circular Barn【USACO 2016 February Contest, Bronze】 (3分)

#include <bits/stdc++.h>

#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < n; j++) {
            sum += x[(i + j) % n] * j;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}