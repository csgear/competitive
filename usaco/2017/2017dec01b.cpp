// https://usaco.org/index.php?page=viewproblem2&cpid=759

// USACO 2017 December Contest, Bronze
// Problem 1. Blocked Billboard

#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1;
    int x2, y2;
    int area() { return (x2 - x1) * (y2 - y1); }
    int overlap(Rectangle r) {
        int left = max(x1, r.x1);
        int right = min(x2, r.x2);
        int bottom = max(y1, r.y1);
        int top = min(y2, r.y2);

        if (left >= right || bottom >= top) {
            return 0;
        }

        return (right - left) * (top - bottom);
    }
};

int overlapArea(Rectangle r1, Rectangle r2) {
    int left = max(r1.x1, r2.x1);
    int right = min(r1.x2, r2.x2);
    int bottom = max(r1.y1, r2.y1);
    int top = min(r1.y2, r2.y2);

    if (left >= right || bottom >= top) {
        return 0;
    }

    return (right - left) * (top - bottom);
}

int main() {
    Rectangle r1, r2, r3;

    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    cin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;

    int area = r1.area() + r2.area() - r3.overlap(r1) - r3.overlap(r2);

    cout << area << endl;

    return 0;
}
