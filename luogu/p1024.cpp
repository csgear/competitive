// https://www.luogu.com.cn/problem/P1024

#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
const double eps = 0.001;
double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

double binary_search(double l, double r) {
    double mid = (l + r) / 2.0;
    if (l >= r - eps) {
        return mid;
    }
    if (f(l) * f(mid) < 0) {
        return binary_search(l, mid);
    } else {
        return binary_search(mid, r);
    }
}

int main() {
    cin >> a >> b >> c >> d;
    double l, r;
    double x[3] = {0, 0, 0};
    int cnt = 0;
    for (int i = -100; i < 100; i++) {
        l = i;
        r = i + 1;
        if (fabs(f(l)) <= eps) {
            x[cnt++] = l;
        };
        if (fabs(f(r)) <= eps) {
            continue;
        };
        if (f(l) * f(r) < 0) {
            x[cnt++] = binary_search(l, r);
        }
        if (cnt == 3) {
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(2) << x[i] << " ";
    }
    return 0;
}