// https://leetcode.cn/problems/burst-balloons/description/
// 312. Burst Balloons

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            balloons[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                for (int k = l; k <= r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] +
                                                 balloons[l - 1] * balloons[k] * balloons[r + 1]);
                }
            }
        }
        return dp[1][n];
    }

    int maxCoins1(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            balloons[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 区间DP模板：先枚举区间长度
        for (int len = 1; len <= n; len++) {          // 区间长度
            for (int l = 1; l + len - 1 <= n; l++) {  // 左端点
                int r = l + len - 1;                  // 右端点
                for (int k = l; k <= r; k++) {        // 分割点
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] +
                                                 balloons[l - 1] * balloons[k] * balloons[r + 1]);
                }
            }
        }
        return dp[1][n];
    }
};