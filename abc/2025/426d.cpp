// https://atcoder.jp/contests/abc426/tasks/abc426_d

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
char s[N];

void solve() {
    int cnt[2] = {0, 0};
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    int mx[2] = {0, 0};
    for (int i = 0; i < n;) {
        int j = i;
        while (s[j + 1] == s[i]) j++;
        mx[s[i] - '0'] = max(mx[s[i] - '0'], j - i + 1);
        i = j + 1;
    }
    cout << min(cnt[1] + 2 * (cnt[0] - mx[0]), cnt[0] + 2 * (cnt[1] - mx[1])) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}