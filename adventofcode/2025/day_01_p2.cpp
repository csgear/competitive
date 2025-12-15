
#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    int n;

    int start = 50, end = 50;

    int ans = 0;

    while (scanf(" %c%d", &c, &n) == 2) {
        if (c == 'L') {
            ans += n / MOD;
            int remainder = n % MOD;

            if (remainder >= start && start > 0) {
                ans++;
            }
            start = (start - remainder + MOD) % MOD;
            end = start;
        } else if (c == 'R') {
            start = start + n;
            ans += start / MOD;
            start = start % MOD;
            end = start;
        }
    }

    printf("%d\n", ans);

    return 0;
}