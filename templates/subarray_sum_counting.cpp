// Template for counting subarrays with given sum
// Various approaches and optimizations

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force O(n²)
int countSubarraysBruteForce(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == target) {
                count++;
            }
        }
    }
    return count;
}

// Approach 2: Prefix Sum + Hash Map O(n)
int countSubarraysOptimized(vector<int>& arr, int target) {
    int n = arr.size();
    long long prefix_sum = 0;
    int count = 0;
    map<long long, int> prefix_count;
    prefix_count[0] = 1;  // Base case: empty subarray

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Look for subarrays ending at i with sum = target
        if (prefix_count.find(prefix_sum - target) != prefix_count.end()) {
            count += prefix_count[prefix_sum - target];
        }

        prefix_count[prefix_sum]++;
    }
    return count;
}

// Approach 3: Sliding Window (for positive numbers only) O(n)
int countSubarraysSlidingWindow(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        // Shrink window from left while sum > target
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }

        // If we found a valid subarray
        if (sum == target) {
            count++;
        }
    }
    return count;
}

// Approach 4: Count subarrays with sum <= target
int countSubarraysLessEqual(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        // Shrink window while sum > target
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }

        // All subarrays ending at right with sum <= target
        count += (right - left + 1);
    }
    return count;
}

// Approach 5: Count subarrays with sum in range [L, R]
int countSubarraysInRange(vector<int>& arr, int L, int R) {
    return countSubarraysLessEqual(arr, R) - countSubarraysLessEqual(arr, L - 1);
}

// Main function for testing
int main() { return 0; }