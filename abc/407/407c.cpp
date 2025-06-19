// https://atcoder.jp/contests/abc407/tasks/abc407_c

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
char s[N];
int main() {
    scanf("%s", s + 1);
    int ans = 0;
    int n = strlen(s + 1);
    s[n + 1] = '0';
    for (int i = 1; i <= n; i++) {
        ans++;
        ans += (s[i] - s[i + 1] + 10) % 10;
    }
    cout << ans << endl;
    return 0;
}