# CSES 05 Range Queries

This section contains solutions for range query problems from CSES Problem Set. The problems cover fundamental data structures including segment trees, binary indexed trees, and advanced query processing techniques.

## Problems Overview

### Static Range Queries

| Problem                                                                      | Data Structure | Complexity     | Key Concepts         |
| ---------------------------------------------------------------------------- | -------------- | -------------- | -------------------- |
| [1646 - Static Range Sum Queries](1646_static_range_sum_queries.cpp)         | Prefix Sum     | O(1) query     | Cumulative sum array |
| [1647 - Static Range Minimum Queries](1647_static_range_minimum_queries.cpp) | Segment Tree   | O(log n) query | Range minimum query  |
| [1650 - Range XOR Queries](1650_range_xor_queries.cpp)                       | Prefix XOR     | O(1) query     | XOR properties       |
| [1652 - Forest Queries](1652_forest_queries.cpp)                             | 2D Prefix Sum  | O(1) query     | 2D range sum         |

### Dynamic Range Queries

| Problem                                                                        | Data Structure   | Complexity | Key Concepts                |
| ------------------------------------------------------------------------------ | ---------------- | ---------- | --------------------------- |
| [1648 - Dynamic Range Sum Queries](1648_dynamic_range_sum_queries.cpp)         | Segment Tree     | O(log n)   | Point update, range query   |
| [1649 - Dynamic Range Minimum Queries](1649_dynamic_range_minimum_queries.cpp) | Segment Tree     | O(log n)   | Point update, range minimum |
| [1651 - Range Update Queries](1651_range_update_queries.cpp)                   | Lazy Propagation | O(log n)   | Range update, lazy prop     |
| [2166 - Prefix Sum Queries](2166_prefix_sum_queries.cpp)                       | Segment Tree     | O(log n)   | Maximum prefix sum          |

### Advanced Range Queries

| Problem                                                          | Data Structure         | Complexity        | Key Concepts                |
| ---------------------------------------------------------------- | ---------------------- | ----------------- | --------------------------- |
| [1190 - Subarray Sum Queries](1190_subarray_sum_queries.cpp)     | Segment Tree           | O(log n)          | Maximum subarray sum        |
| [1144 - Salary Queries](1144_salary_queries.cpp)                 | Coordinate Compression | O(log n)          | Dynamic range counting      |
| [1734 - Distinct Value Queries](1734_distinct_value_queries.cpp) | Mo's Algorithm/BIT     | O(n√n)/O(n log n) | Offline queries             |
| [2206 - Pizzeria Queries](2206_pizzeria_queries.cpp)             | Dual Segment Trees     | O(log n)          | Distance-based optimization |

### Order Statistics & Special

| Problem                                                          | Data Structure        | Complexity | Key Concepts             |
| ---------------------------------------------------------------- | --------------------- | ---------- | ------------------------ |
| [1143 - Hotel Queries](1143_hotel_queries.cpp)                   | Segment Tree          | O(log n)   | First fit allocation     |
| [1749 - List Removals](1749_list_removals.cpp)                   | Segment Tree          | O(log n)   | Order statistics         |
| [3226 - Subarray Sum Queries 2](3226_subarray_sum_queries_2.cpp) | Advanced Segment Tree | O(log n)   | Complex range operations |

## Data Structure Categories

### **Segment Trees**

- **Basic Operations**: Point update, range query
- **Lazy Propagation**: Range updates with deferred propagation
- **Multi-value Nodes**: Storing multiple values per node
- **Order Statistics**: Finding k-th element efficiently

### **Coordinate Compression**

- **Large Value Ranges**: Map large values to smaller indices
- **Dynamic Queries**: Handle values not known in advance
- **Applications**: Salary queries, dynamic range problems

### **Specialized Techniques**

- **Mo's Algorithm**: Offline query processing with sqrt decomposition
- **2D Range Queries**: Extension to higher dimensions
- **Distance Optimization**: Split absolute value into cases

## Key Implementation Patterns

### 1. Basic Segment Tree

```cpp
struct SegmentTree {
    vector<ll> tree;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(2*v, tl, tm, l, min(r, tm)) +
               query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }
};
```

### 2. Lazy Propagation

```cpp
struct LazySegTree {
    vector<ll> tree, lazy;

    void push(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v] * (tr - tl + 1);
            if (tl != tr) {
                lazy[2*v] += lazy[v];
                lazy[2*v+1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, ll val) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] += val;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        push(2*v, tl, tm);
        push(2*v+1, tm+1, tr);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
};
```

### 3. Maximum Subarray Segment Tree

```cpp
struct SubarrayTree {
    struct Node {
        ll sum, maxPrefix, maxSuffix, maxSubarray;
        Node() : sum(0), maxPrefix(0), maxSuffix(0), maxSubarray(0) {}
        Node(ll val) : sum(val), maxPrefix(val), maxSuffix(val), maxSubarray(val) {}
    };

    Node combine(Node left, Node right) {
        Node result;
        result.sum = left.sum + right.sum;
        result.maxPrefix = max(left.maxPrefix, left.sum + right.maxPrefix);
        result.maxSuffix = max(right.maxSuffix, right.sum + left.maxSuffix);
        result.maxSubarray = max({left.maxSubarray, right.maxSubarray,
                                 left.maxSuffix + right.maxPrefix});
        return result;
    }
};
```

### 4. Coordinate Compression

```cpp
vector<int> vals; // All values that will be queried
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

int compress(int x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
}
```

## Advanced Problem Techniques

### **Distance-Based Queries (Pizzeria)**

Split absolute value |a - k| into two cases:

- Left case (a ≤ k): cost = k + (p[a] - a)
- Right case (a ≥ k): cost = (p[a] + a) - k

Use two segment trees for efficient range minimum queries.

### **Maximum Subarray with Updates**

Store four values per node:

- Total sum of range
- Maximum prefix sum
- Maximum suffix sum
- Maximum subarray sum

Combine nodes by considering all possible subarray positions.

### **Order Statistics Trees**

Use segment tree to simulate array operations:

- Each leaf represents presence/absence of element
- Internal nodes store count of elements in subtree
- Find k-th element by binary search on tree structure

## Problem-Solving Insights

1. **Data Structure Selection**: Choose based on query/update patterns
2. **Lazy Propagation**: Essential for range updates
3. **Multi-value Nodes**: Store multiple properties for complex queries
4. **Coordinate Compression**: Handle large value ranges efficiently
5. **Offline Processing**: Mo's algorithm for complex queries
6. **Case Analysis**: Split complex conditions into simpler cases
