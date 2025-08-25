// https://usaco.org/index.php?page=viewproblem2&cpid=711
// USACO 2017 February Contest, Bronze
// Problem 1. Why Did the Cow Cross the Road

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pos(n + 1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cow, side;
        cin >> cow >> side;
        if (pos[cow] != -1 && pos[cow] != side) {
            ans++;
        }
        pos[cow] = side;
    }
    cout << ans << endl;
    return 0;
}