// https://usaco.org/index.php?cpid=567&page=viewproblem2
// USACO 2015 December Contest, Bronze
// Problem 1. Fence Painting

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Ensure a <= b and c <= d
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    // Calculate the total painted length
    int left = max(a, c);
    int right = min(b, d);

    int overlap = max(0, right - left);
    int total = (b - a) + (d - c) - overlap;

    cout << total << endl;
    return 0;
}
