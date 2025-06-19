// https://dmoj.ca/problem/ccc25s1
// CCC '25 S1 - Positioning Peter's Paintings

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    int overlapX = min(A, X);
    int overlapY = min(B, Y);

    int total = 2 * (A + B) + 2 * (X + Y);
    int ans = min(total - 2 * overlapX, total - 2 * overlapY);
    cout << ans << endl;
    return 0;
}