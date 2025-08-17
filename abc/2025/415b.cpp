// https://atcoder.jp/contests/abc415/tasks/abc415_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    pair<int, int> ans = {0, 0};
    int current = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (current % 2 == 0) {
                ans.first = i + 1;
            } else if (current % 2 == 1) {
                ans.second = i + 1;
                cout << ans.first << "," << ans.second << endl;
            }
            current++;
        }
    }
    return 0;
}