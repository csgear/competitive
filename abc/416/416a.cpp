// https://atcoder.jp/contests/abc416/tasks/abc416_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    bool flag = true;
    for (int i = l; i <= r; i++) {
        if (s[i - 1] != 'o') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}