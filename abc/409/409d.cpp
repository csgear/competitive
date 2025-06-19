// https://atcoder.jp/contests/abc409/tasks/abc409_d

#include <bits/stdc++.h> ;
using namespace std;

void solve(int t, string s) {
    for (int l = 0; l < t - 1; l++) {
        if (s[l] > s[l + 1]) {
            for (int r = l; r + 1 < t; ++r) {
                if (s[r] >= s[r + 1]) {
                    swap(s[r], s[r + 1]);
                } else {
                    break;
                }
            }
            break;
        }
    }
    cout << s << endl;
}

int main() {
    int n;
    cin >> n;
    int t;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> t;
        cin >> s;
        solve(t, s);
    }
    return 0;
}