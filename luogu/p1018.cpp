
// https://www.luogu.com.cn/problem/P1018

#include <bits/stdc++.h>
using namespace std;

long long getVal(const string& s, int l, int r) { return stoll(s.substr(l, r - l + 1)); }

int main() {
    string s;
    int K;
    cin >> s >> K;
    int N = s.size();

    // dp[i][k]：前i个字符，插k个乘号，最大乘积
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));

    // 初始化：没有乘号
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = getVal(s, 0, i - 1);
    }

    for (int k = 1; k <= K; ++k) {
        for (int i = k + 1; i <= N; ++i) {  // 至少需要k+1个数字
            for (int j = k; j < i; ++j) {   // 枚举最后一个乘号的位置
                long long left = dp[j][k - 1];
                long long right = getVal(s, j, i - 1);
                dp[i][k] = max(dp[i][k], left * right);
            }
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}
