// https://usaco.org/index.php?page=viewproblem2&cpid=595
// USACO 2016 January Contest, Silver
// Problem 2. Subsequences Summing to Sevens

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e4 + 5;

int n;

int main() {
    cin >> n;
    vector<int> first_pos(7, -1);
    first_pos[0] = 0;

    LL pre = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre += x;

        int rem = ((pre % 7) + 7) % 7;

        if (first_pos[rem] != -1) {
            ans = max(ans, i - first_pos[rem]);
        } else {
            first_pos[rem] = i;
        }
    }

    cout << ans << endl;
    return 0;
}