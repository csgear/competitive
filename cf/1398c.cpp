// https://codeforces.com/contest/1398/problem/C

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    map<int, int> count;
    count[0] = 1;

    vector<int> prefix(n + 1, 0);
    LL ans = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (s[i] - '0');
        int transformed = prefix[i] - i;
        ans += count[transformed];
        count[transformed]++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}