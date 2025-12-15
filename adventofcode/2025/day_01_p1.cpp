
#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    int n;

    int pos = 50;

    int ans = 0;

    while (scanf(" %c%d", &c, &n) == 2) {
        if (c == 'L') {
            pos = (pos + MOD - n) % MOD;
        } else if (c == 'R') {
            pos = (pos + n) % MOD;
        }
        if (pos == 0) ans++;
        // printf("%d\n", pos);
    }

    printf("%d\n", ans);

    return 0;
}