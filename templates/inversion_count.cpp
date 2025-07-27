// 普通逆序对问题 - 归并排序解法
// 逆序对定义：对于 i < j，如果 nums[i] > nums[j]，则 (i, j) 是一个逆序对

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        long long count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        // 统计跨越两个子数组的逆序对
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                // nums[i] > nums[j]，说明从 i 到 mid 的所有元素都与 nums[j] 构成逆序对
                temp[k++] = nums[j++];
                count += mid - i + 1;  // 关键：统计逆序对数量
            }
        }
        
        // 复制剩余元素
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        // 将排序后的结果复制回原数组
        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
        
        return count;
    }
    
public:
    long long countInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// BIT 解法（作为对比）
class SolutionBIT {
private:
    class BIT {
    private:
        vector<int> tree;
        int n;
    public:
        BIT(int _n) : n(_n), tree(_n + 1) {}
        
        static constexpr int lowbit(int x) { return x & (-x); }
        
        void update(int x, int d) {
            while (x <= n) {
                tree[x] += d;
                x += lowbit(x);
            }
        }
        
        int query(int x) const {
            int ans = 0;
            while (x) {
                ans += tree[x];
                x -= lowbit(x);
            }
            return ans;
        }
    };
    
public:
    long long countInversions(vector<int>& nums) {
        // 坐标压缩
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());
        
        unordered_map<int, int> rank;
        for (int i = 0; i < sorted_nums.size(); i++) {
            rank[sorted_nums[i]] = i + 1;
        }
        
        long long count = 0;
        BIT bit(sorted_nums.size());
        
        // 从右往左处理
        for (int i = nums.size() - 1; i >= 0; i--) {
            int r = rank[nums[i]];
            count += bit.query(r - 1);  // 查询比当前元素小的元素个数
            bit.update(r, 1);
        }
        
        return count;
    }
};

// BIT解法详细解释：
// 数组 [7, 5, 6, 4] 的处理过程：
//
// 1. 坐标压缩：4->1, 5->2, 6->3, 7->4
// 2. 从右往左处理：
//    - i=3, nums[3]=4, rank=1: query(0)=0, 然后 update(1,1)
//    - i=2, nums[2]=6, rank=3: query(2)=1 (比6小的有4), 然后 update(3,1)  
//    - i=1, nums[1]=5, rank=2: query(1)=1 (比5小的有4), 然后 update(2,1)
//    - i=0, nums[0]=7, rank=4: query(3)=3 (比7小的有4,5,6), 然后 update(4,1)
//    - 总逆序对：0+1+1+3=5

// 特殊情况：当数组元素范围有限时，可以用计数排序思想达到 O(n × k)
// 其中 k 是元素值域大小，只有当 k << log n 时才比 O(n log n) 更优
class SolutionLinear {
public:
    long long countInversions(vector<int>& nums, int minVal, int maxVal) {
        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);
        
        long long inversions = 0;
        
        // 从右往左扫描
        for (int i = nums.size() - 1; i >= 0; i--) {
            int val = nums[i] - minVal;  // 标准化到 [0, range-1]
            
            // 统计比当前元素小的已出现元素个数
            for (int j = 0; j < val; j++) {
                inversions += count[j];
            }
            
            count[val]++;
        }
        
        return inversions;
    }
};

// 数组元素只有0和1的特殊情况 - 真正的O(n)
class SolutionBinary {
public:
    long long countInversions(vector<int>& nums) {
        // 只包含0和1的数组
        long long inversions = 0;
        int onesCount = 0;
        
        // 从右往左扫描
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                onesCount++;
            } else {  // nums[i] == 0
                // 每个0与其右边的所有1构成逆序对
                inversions += onesCount;
            }
        }
        
        return inversions;
    }
};

// 测试用例
int main() {
    // 一般情况测试
    vector<int> nums = {7, 5, 6, 4};
    
    Solution sol1;
    SolutionBIT sol2;
    
    vector<int> nums1 = nums, nums2 = nums;
    
    cout << "归并排序解法: " << sol1.countInversions(nums1) << endl;
    cout << "BIT解法: " << sol2.countInversions(nums2) << endl;
    
    // 特殊情况测试：值域有限
    SolutionLinear sol3;
    vector<int> nums3 = {7, 5, 6, 4};
    cout << "值域有限解法: " << sol3.countInversions(nums3, 4, 7) << endl;
    
    // 特殊情况测试：只有0和1
    SolutionBinary sol4;
    vector<int> binary = {1, 0, 1, 0, 1};
    cout << "二进制数组解法: " << sol4.countInversions(binary) << endl;
    
    return 0;
}
