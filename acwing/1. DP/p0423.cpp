// https://www.acwing.com/problem/content/425/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int T, M;
    cin >> T >> M;
    vector<int> t(M + 1), v(M + 1), dp(T + 1);
    for (int i = 1; i <= M; i++) {
        cin >> t[i] >> v[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = T; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }

    cout << dp[T] << endl;
    return 0;
}