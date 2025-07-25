// Fenwick Tree (Binary Indexed Tree) Template
// Array-based implementation for competitive programming
// 1-indexed for easier implementation

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int lowbit(int x) { return x & -x; }

int tree[MAXN];
int n;

// Initialize BIT with size n
void init(int size) {
    n = size;
    for (int i = 0; i <= n; i++) {
        tree[i] = 0;
    }
}

// Add val to position idx (1-indexed)
void update(int idx, int val) {
    for (int i = idx; i <= n; i += lowbit(i)) {
        tree[i] += val;
    }
}

// Get prefix sum from 1 to idx (1-indexed)
int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

// Get range sum from left to right (1-indexed, inclusive)
int rangeQuery(int left, int right) { return query(right) - query(left - 1); }
