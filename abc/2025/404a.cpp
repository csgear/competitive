// https://atcoder.jp/contests/abc404/tasks/abc404_a

#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            cout << char('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}