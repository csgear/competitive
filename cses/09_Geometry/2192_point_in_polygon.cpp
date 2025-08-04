// https://cses.fi/problemset/task/2192

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};

long long cross(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool onSegment(const Point& a, const Point& b, const Point& p) {
    if (cross(a, b, p) != 0) return false;
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y &&
           p.y <= max(a.y, b.y);
}

bool pointInPolygon(const vector<Point>& poly, const Point& p) {
    int n = poly.size();
    bool inside = false;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        if (onSegment(poly[i], poly[j], p)) {
            return false;
        }

        if ((poly[i].y > p.y) != (poly[j].y > p.y)) {
            // Use cross product to avoid floating point division
            long long cross_val = (poly[j].x - poly[i].x) * (p.y - poly[i].y) -
                                  (poly[j].y - poly[i].y) * (p.x - poly[i].x);
            if ((poly[j].y > poly[i].y && cross_val > 0) ||
                (poly[j].y < poly[i].y && cross_val < 0)) {
                inside = !inside;
            }
        }
    }

    return inside;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }

    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y;

        bool onBoundary = false;
        for (int j = 0; j < n; j++) {
            int k = (j + 1) % n;
            if (onSegment(poly[j], poly[k], p)) {
                onBoundary = true;
                break;
            }
        }

        if (onBoundary) {
            cout << "BOUNDARY\n";
        } else if (pointInPolygon(poly, p)) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }

    return 0;
}
