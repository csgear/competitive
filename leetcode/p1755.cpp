
// leetcode 1755:  https://leetcode.cn/problems/closest-subsequence-sum/description/
class Solution {
   public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        int ls = half, rs = n - half;

        // natural iteration approach
        vector<int> lsum(1 << ls);
        for (int i = 0; i < half; i++) {
            for (int mask = 0; mask < (1 << ls); mask++) {
                if (mask & (1 << i)) {
                    lsum[mask] = lsum[mask ^ (1 << i)] + nums[i];
                }
            }
        }
        // another way to generate the set, find the lowbit of i
        // vector<int> lsum(1 << ls, 0);
        // for (int i = 1; i < (1 << ls); i++) {
        //     for (int j = 0; j < ls; j++) {
        //         if ((i & (1 << j)) == 0) continue;
        //         lsum[i] = lsum[i-(1<<j)] + nums[j];
        //         break;
        //     }
        // }

        vector<int> rsum(1 << rs);
        for (int i = 0; i < rs; i++) {
            for (int mask = 0; mask < (1 << rs); mask++) {
                if (mask & (1 << i)) {
                    rsum[mask] = rsum[mask ^ (1 << i)] + nums[i + ls];
                }
            }
        }

        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());

        int ret = INT_MAX;

        for (int x : lsum) {
            ret = min(ret, abs(goal - x));
        }

        for (int x : rsum) {
            ret = min(ret, abs(goal - x));
        }

        // two points to pick one subset from left and another from right
        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            ret = min(ret, abs(goal - s));
            if (s > goal) {
                j--;
            } else {
                i++;
            }
        }

        return ret;
    }
};