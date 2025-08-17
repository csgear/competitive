// https://atcoder.jp/contests/abc407/tasks/abc407_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int total = 36;
    int cnt = 0;
    for (int x1 = 1; x1 <= 6; x1++) {
        for (int x2 = 1; x2 <= 6; x2++) {
            if (x1 + x2 >= X || abs(x1 - x2) >= Y) {
                cnt++;
            }
        }
    }
    double prob = (double)cnt / total;
    cout << fixed << setprecision(10) << prob << endl;
    return 0;
}