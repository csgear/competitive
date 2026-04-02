// https://leetcode.cn/problems/reverse-pairs/description/

// Merge sort solution: count reverse pairs during merge process

class Solution {
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        // Count reverse pairs across the two halves
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                count += mid - i + 1;  // All elements from i to mid form reverse pairs with nums[j]
                j++;
            } else {
                i++;
            }
        }
        
        // Merge the two sorted halves
        vector<int> temp(right - left + 1);
        i = left;
        j = mid + 1;
        int k = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        // Copy back to original array
        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
        
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
