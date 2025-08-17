// https://atcoder.jp/contests/abc418/tasks/abc418_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s.length() >= 3 && s.substr(s.length() - 3) == "tea") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}