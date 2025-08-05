// https://www.luogu.com.cn/problem/P2657

#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 11;

int dp[MAXLEN][10][2];

void build(int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}

int f(int num, int offset, int len, int pre, int tight) {
    if (len == 0) {
        return 1;
    }
    // Use pre >= 0 to check if dp state is valid
    if (pre >= 0 && dp[len - 1][pre][tight] != -1) {
        return dp[len - 1][pre][tight];
    }
    int cur = num / offset % 10;
    int limit = tight ? cur : 9;
    int ans = 0;

    for (int i = 0; i <= limit; i++) {
        if (pre == -1) {
            // First digit - no constraint check needed
            if (i == 0) {
                // Leading zero - continue with pre = -1
                ans += f(num, offset / 10, len - 1, -1, tight && (i == limit));
            } else {
                // First non-zero digit
                ans += f(num, offset / 10, len - 1, i, tight && (i == limit));
            }
        } else {
            // Subsequent digits - check constraint
            if (abs(i - pre) >= 2) {
                ans += f(num, offset / 10, len - 1, i, tight && (i == limit));
            }
        }
    }

    // Only memoize if pre >= 0 (valid array index)
    if (pre >= 0) {
        dp[len - 1][pre][tight] = ans;
    }
    return ans;
}

int cnt(int num) {
    if (num == 0) {
        return 1;  // Zero is a valid single digit number
    }
    int len = 1;
    int offset = 1;
    int tmp = num / 10;
    while (tmp > 0) {
        len++;
        offset *= 10;
        tmp /= 10;
    }
    build(len);
    return f(num, offset, len, -1, 1);
}

int compute(int a, int b) { return cnt(b) - cnt(a - 1); }

int main() {
    int a, b;
    cin >> a >> b;
    cout << compute(a, b) << endl;
    return 0;
}