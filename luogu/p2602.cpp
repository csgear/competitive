// https://www.luogu.com.cn/problem/P2602

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 15;

ll dp[N][N][2][2];

int tot = 0, num[N];

ll dfs(int pos, int count, int d, int limit, int lead) {
    ll ans = 0;
    if (pos == tot + 1) {
        return count;
    }
    if (dp[pos][count][limit][lead] != -1) {
        return dp[pos][count][limit][lead];
    }

    int up = limit ? num[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (lead && i == 0) {
            ans += dfs(pos + 1, count, d, 0, 1);
        } else {
            ans += dfs(pos + 1, count + (i == d), d, limit && (i == num[pos]), 0);
        }
    }
    return dp[pos][count][limit][lead] = ans;
}

// count d in numbers from 1 to x
ll countDigit(int d, ll x) {
    memset(dp, -1, sizeof(dp));
    tot = 0;
    while (x) {
        num[++tot] = x % 10;
        x /= 10;
    }

    for (int i = 1; i <= tot / 2; i++) {
        swap(num[i], num[tot - i + 1]);
    }
    return dfs(1, 0, d, 1, 1);
}

int main() {
    ll a, b;
    cin >> a >> b;

    for (int i = 0; i <= 9; i++) {
        cout << countDigit(i, b) - countDigit(i, a - 1);
        if (i < 9) cout << " ";
    }
    cout << endl;
    return 0;
}