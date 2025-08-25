// https://atcoder.jp/contests/abc420/tasks/abc420_a

#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << (x + y - 1) % 12 + 1 << endl;
    return 0;
}