#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;
using ll = long long;

vector<Point> pts;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (scanf("%d,%d", &x, &y) == 2) {
        pts.push_back({x, y});
    }

    int n = pts.size();

    ll maxArea = 0;

    // Try all pairs of points as opposite corners of rectangle
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll width = abs(pts[i].first - pts[j].first) + 1;
            ll height = abs(pts[i].second - pts[j].second) + 1;
            ll area = width * height;
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}