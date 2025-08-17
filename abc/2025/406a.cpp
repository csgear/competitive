// https://atcoder.jp/contests/abc406/tasks/abc406_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < c || (a == c && b < d)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}