// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// 1312. Minimum Insertion Steps to Make a String Palindrome

class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }

    int minInsertions1d(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        // dp[j] = minimum insertions for substring s[i..j]
        for (int i = n - 1; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];  // dp[i+1][j]
                if (s[i] == s[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + 1;
                }
                prev = temp;  // dp[i+1][j-1] for next iteration
            }
        }
        return dp[n - 1];
    }
};