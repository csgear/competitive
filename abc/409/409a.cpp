// https://atcoder.jp/contests/abc409/tasks/abc409_a

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string t, a;
    cin >> t >> a;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'o' && a[i] == 'o') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}