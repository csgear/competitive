// https://www.acwing.com/problem/content/104/
// 102. 最佳牛围栏

#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N];
double s[N];
int F;
int n;

bool check(double avg) {
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (a[i] - avg);
    }

    double min_s = 0;
    for (int i = F; i <= n; i++) {
        min_s = min(min_s, (double)s[i - F]);
        if (s[i] - min_s >= 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> F;
    double l = 0, r = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, (double)a[i]);
    }

    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << (int)(r * 1000) << endl;

    return 0;
}