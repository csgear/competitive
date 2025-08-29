// https://usaco.org/index.php?page=viewproblem2&cpid=783
// USACO 2018 January Contest, Bronze
// Problem 1. Blocked Billboard II

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int totalArea = (x2 - x1) * (y2 - y1);

    if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
        totalArea = 0;
    } else if (x3 <= x1 && x4 >= x1 && y3 <= y1 && y4 >= y2) {
        // cover left side
        totalArea = (x2 - x4) * (y2 - y1);
    } else if (x3 <= x2 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        // cover right side
        totalArea = (x3 - x1) * (y2 - y1);
    } else if (y3 <= y1 && y4 >= y1 && x3 <= x1 && x4 >= x2) {
        // cover top side
        totalArea = (x2 - x1) * (y2 - y4);
    } else if (y3 <= y2 && y4 >= y2 && x3 <= x1 && x4 >= x2) {
        // cover bottom side
        totalArea = (x2 - x1) * (y3 - y1);
    }

    cout << totalArea << endl;

    return 0;
}