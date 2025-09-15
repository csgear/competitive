// https://usaco.org/index.php?page=viewproblem2&cpid=896
// USACO 2019 January Contest, Silver
// Problem 3. Mountain View

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct Mountain {
    LL x, y;
    LL left, right;
};

int main() {
    int n;
    cin >> n;

    vector<Mountain> mountains(n);
    for (int i = 0; i < n; i++) {
        cin >> mountains[i].x >> mountains[i].y;
        mountains[i].left = mountains[i].x - mountains[i].y;
        mountains[i].right = mountains[i].x + mountains[i].y;
    }

    sort(mountains.begin(), mountains.end(), [](const Mountain& a, const Mountain& b) {
        if (a.left != b.left) return a.left < b.left;
        return a.right > b.right;
    });

    LL max_right = LLONG_MIN;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (mountains[i].right > max_right) {
            ans++;
            max_right = mountains[i].right;
        }
    }

    cout << ans << endl;
    return 0;
}
