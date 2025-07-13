// https://atcoder.jp/contests/abc414/tasks/abc414_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;
    char c;
    long long l;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> c >> l;
        total += l;
        if (total > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        ans += string(l, c);
    }
    cout << ans << endl;
    return 0;
}