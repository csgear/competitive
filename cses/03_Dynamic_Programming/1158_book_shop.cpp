// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXX = 100005;
int price[MAXN], pages[MAXN], dp[MAXX];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}