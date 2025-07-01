// https://cses.fi/problemset/task/2189

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x1, y1, x2, y2, x3, y3;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // orientation test: vector P1P2 x P1P3
        long long test = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

        if (test > 0) {
            cout << "LEFT" << endl;
        } else if (test < 0) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }
    return 0;
}