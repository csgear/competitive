// https://leetcode.cn/problems/reverse-pairs/description/
// 动态开点线段树解法：避免离散化，直接处理大范围坐标

#include <bits/stdc++.h>
using namespace std;

class DynamicSegmentTree {
   private:
    struct Node {
        int count;
        Node* left;
        Node* right;

        Node() : count(0), left(nullptr), right(nullptr) {}
    };

    Node* root;
    long long minVal, maxVal;

    void update(Node*& node, long long l, long long r, long long pos, int val) {
        if (!node) node = new Node();

        node->count += val;
        if (l == r) return;

        long long mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(node->left, l, mid, pos, val);
        } else {
            update(node->right, mid + 1, r, pos, val);
        }
    }

    int query(Node* node, long long l, long long r, long long ql, long long qr) {
        if (!node || ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return node->count;

        long long mid = l + (r - l) / 2;
        return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
    }

   public:
    DynamicSegmentTree(long long minV, long long maxV)
        : root(nullptr), minVal(minV), maxVal(maxV) {}

    void update(long long pos, int val) { update(root, minVal, maxVal, pos, val); }

    int query(long long l, long long r) {
        if (l > r) return 0;
        return query(root, minVal, maxVal, l, r);
    }

    ~DynamicSegmentTree() {}
};

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        DynamicSegmentTree segTree(INT_MIN, INT_MAX);

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long target = 2LL * nums[i];

            if (target < INT_MAX) {
                result += segTree.query(target + 1, INT_MAX);
            }
            segTree.update(nums[i], 1);
        }

        return result;
    }
};
