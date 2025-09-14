// https://atcoder.jp/contests/abc405/tasks/abc405_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, X;
    cin >> R >> X;
    if (X == 1 && 1600 <= R && R <= 2999 || X == 2 && 1200 <= R && R <= 2399) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}