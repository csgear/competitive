

class Solution {
   public:
    /*
     * https://leetcode.com/problems/shifting-letters-ii/
     */

    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        int n = s.length();
        std::vector<int> prefix_sum(n + 1, 0);

        for (const std::vector<int>& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 0) {
                prefix_sum[start] -= 1;
                prefix_sum[end + 1] += 1;
            } else {
                prefix_sum[start] += 1;
                prefix_sum[end + 1] -= 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            prefix_sum[i] += prefix_sum[i - 1];
        }

        std::string result;
        for (int i = 0; i < n; i++) {
            int shift_amount = (s[i] - 'a' + prefix_sum[i]) % 26;
            if (shift_amount < 0) shift_amount += 26;
            result += (char)(shift_amount + 'a');
        }

        return result;
    }
};
