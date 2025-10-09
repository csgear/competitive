// https://atcoder.jp/contests/abc426/tasks/abc426_e

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

struct Point {
    double x, y;
};

Point sa, ta, sb, tb;
double disa, disb;

double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// calculate distance between two points at time t
double cal(double t) {
    Point pa, pb;
    if (t >= disa) {
        pa = ta;
    } else {
        pa = {sa.x + (ta.x - sa.x) / disa * t, sa.y + (ta.y - sa.y) / disa * t};
    }
    if (t >= disb) {
        pb = tb;
    } else {
        pb = {sb.x + (tb.x - sb.x) / disb * t, sb.y + (tb.y - sb.y) / disb * t};
    }
    return distance(pa, pb);
}

void solve() {
    cin >> sa.x >> sa.y >> ta.x >> ta.y;
    cin >> sb.x >> sb.y >> tb.x >> tb.y;
    disa = distance(sa, ta);
    disb = distance(sb, tb);

    double ans = min(cal(0.0), min(cal(disa), cal(disb)));
    double l = 0.0;
    double r = min(disa, disb);
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (cal(m1) > cal(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    ans = min(ans, cal((l + r) / 2));
    l = min(disa, disb);
    r = max(disa, disb);
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (cal(m1) > cal(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    ans = min(ans, cal((l + r) / 2));
    cout << fixed << setprecision(15) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}