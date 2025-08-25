// https://leetcode.cn/problems/count-of-range-sum/description/
// BIT + 离散化解法：前缀和 + 树状数组

class BIT {
   private:
    vector<int> tree;
    int n;

   public:
    BIT(int _n) : n(_n), tree(_n + 1, 0) {}

    static constexpr int lowbit(int x) { return x & (-x); }

    void update(int x, int d) {
        while (x <= n) {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

    int rangeQuery(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
   public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        set<long long> allValues;
        for (long long sum : prefixSum) {
            allValues.insert(sum);
            allValues.insert(sum - lower);
            allValues.insert(sum - upper);
        }

        unordered_map<long long, int> compress;
        int idx = 0;
        for (long long val : allValues) {
            compress[val] = ++idx;
        }

        BIT bit(allValues.size());
        int result = 0;

        // 先将 prefixSum[0] = 0 加入 BIT
        bit.update(compress[prefixSum[0]], 1);

        // 从 prefixSum[1] 开始处理
        for (int i = 1; i <= n; i++) {
            // 查询满足条件的前缀和个数
            // 需要找到 prefixSum[j] 使得 lower <= prefixSum[i] - prefixSum[j] <= upper
            // 即：prefixSum[i] - upper <= prefixSum[j] <= prefixSum[i] - lower
            long long leftBound = prefixSum[i] - upper;
            long long rightBound = prefixSum[i] - lower;

            result += bit.rangeQuery(compress[leftBound], compress[rightBound]);

            // 将当前前缀和加入BIT
            bit.update(compress[prefixSum[i]], 1);
        }

        return result;
    }
};