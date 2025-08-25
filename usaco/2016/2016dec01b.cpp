// https://usaco.org/index.php?page=viewproblem2&cpid=663
// USACO 2016 December Contest, Bronze
// Problem 1. Square Pasture

#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int min_x = min({x1, x2, x3, x4});
    int max_x = max({x1, x2, x3, x4});
    int min_y = min({y1, y2, y3, y4});
    int max_y = max({y1, y2, y3, y4});

    int side_length = max(max_x - min_x, max_y - min_y);

    cout << side_length * side_length << endl;

    return 0;
}