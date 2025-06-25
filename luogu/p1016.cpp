// https :  // www.luogu.com.cn/problem/P1016

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
double d[MAXN], v[MAXN];
double d1, c, d2, p;
double ans, last;
int n;

int main() {
    cin >> d1 >> c >> d2 >> p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> v[i];
    }
    d[n + 1] = d1;
    v[0] = p;

    for (int i = 1; i <= n; i++) {
        if (d[i + 1] - d[i] > c * d2) {
            cout << "No Solution" << endl;
            return 0;
        }
    }

    int j;

    for (int i = 0; i <= n; i = j) {
        for (j = i + 1; j <= n + 1; j++) {
            if (d[j] - d[i] > c * d2) {
                j--;
                break;
            }
            if (v[j] < v[i]) {
                break;
            }
        }

        if (v[j] < v[i]) {
            ans += ((d[j] - d[i]) / d2 - last) * v[i];
            last = 0;
        } else {
            ans += (c - last) * v[i];
            last = c - (d[j] - d[i]) / d2;
        }
    }

    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
