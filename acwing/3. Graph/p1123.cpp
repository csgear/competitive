// https://www.acwing.com/problem/content/1125/
// 1123. 铲雪车

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    double dist = 0;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        dist += sqrt(dx * dx + dy * dy) * 2;
    }
    int minutes = round(dist / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;
    printf("%d:%02d\n", hours, minutes);
    return 0;
}
