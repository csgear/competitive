// https://atcoder.jp/contests/abc416/tasks/abc416_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.' && (s[i - 1] == '#' || i == 0)) {
            s[i] = 'o';
        }
    }
    cout << s << endl;
    return 0;
}