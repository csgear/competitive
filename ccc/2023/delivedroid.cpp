// https://dmoj.ca/problem/ccc23j1

#include <bits/stdc++.h>

using namespace std;

int main() {
    int G, L;
    cin >> G >> L;

    int score = G * 50 - L * 10;

    if (G > L) {
        score += 500;
    }

    cout << score << endl;

    return 0;
}