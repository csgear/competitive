// https://atcoder.jp/contests/abc415/tasks/abc415_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            ans = i;
            break;
        }
    }
    if (ans != -1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}