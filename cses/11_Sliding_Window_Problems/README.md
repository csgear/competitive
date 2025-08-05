# CSES 11 Sliding Window Problems

This section contains solutions for sliding window problems from CSES Problem Set. These problems cover various sliding window techniques including order statistics, frequency counting, and bitwise operations.

## Problems Overview

### Basic Sliding Window Operations

| Problem                                                  | Algorithm       | Complexity     | Key Concepts                  |
| -------------------------------------------------------- | --------------- | -------------- | ----------------------------- |
| [3220 - Sliding Window Sum](3220_sliding_window_sum.cpp) | Queue           | O(n)           | Sum tracking, XOR aggregation |
| [3426 - Sliding Window XOR](3426_sliding_window_xor.cpp) | Incremental XOR | O(n)           | Self-inverse property         |
| [3405 - Sliding Window OR](3405_sliding_window_or.cpp)   | Bit Frequency   | O(n × log max) | Bitwise OR tracking           |

### Order Statistics in Windows

| Problem                                                          | Algorithm             | Complexity | Key Concepts              |
| ---------------------------------------------------------------- | --------------------- | ---------- | ------------------------- |
| [1076 - Sliding Window Median](1076_sliding_window_median.cpp)   | Two Multisets         | O(n log k) | Balanced sets for median  |
| [1077 - Sliding Window Cost](1077_sliding_window_cost.cpp)       | Median + Sum Tracking | O(n log k) | Cost optimization         |
| [3221 - Sliding Window Minimum](3221_sliding_window_minimum.cpp) | Monotonic Deque       | O(n)       | Efficient min/max queries |

### Frequency and Counting

| Problem                                                                          | Algorithm              | Complexity | Key Concepts              |
| -------------------------------------------------------------------------------- | ---------------------- | ---------- | ------------------------- |
| [3222 - Sliding Window Distinct Values](3222_sliding_window_distinct_values.cpp) | Frequency Map          | O(n)       | Distinct element counting |
| [3224 - Sliding Window Mode](3224_sliding_window_mode.cpp)                       | Frequency-of-Frequency | O(n)       | Mode tracking             |
| [3219 - Sliding Window MEX](3219_sliding_window_mex.cpp)                         | Missing Value Set      | O(n log k) | MEX computation           |

## Algorithm Categories

### **Basic Window Maintenance**

- **Sum/XOR Operations**: Simple add/remove with mathematical properties
- **Incremental Updates**: Leveraging self-inverse properties (XOR)
- **Bitwise Operations**: Bit frequency counting for OR operations

### **Order Statistics**

- **Median Finding**: Two balanced multisets technique
- **Cost Calculation**: Combining median with sum tracking
- **Min/Max Queries**: Monotonic deque for optimal performance

### **Advanced Counting**

- **Distinct Elements**: Frequency maps with entry/exit tracking
- **Mode Detection**: Frequency-of-frequency data structures
- **MEX Calculation**: Missing value tracking with efficient lookups

## Key Implementation Patterns

### 1. Two Multisets for Median

```cpp
multiset<int> left, right;  // left has smaller half, right has larger half

void balance() {
    while (left.size() > right.size() + 1) {
        right.insert(*left.rbegin());
        left.erase(left.find(*left.rbegin()));
    }
    while (right.size() > left.size()) {
        left.insert(*right.begin());
        right.erase(right.begin());
    }
}

int getMedian() {
    return *left.rbegin();  // Median is always max of left set
}
```

### 2. Monotonic Deque for Min/Max

```cpp
deque<pair<int, int>> dq;  // {value, index}

void addElement(int val, int idx) {
    while (!dq.empty() && dq.back().first >= val) {
        dq.pop_back();  // Remove larger elements
    }
    dq.push_back({val, idx});
}

void removeOutside(int leftBound) {
    while (!dq.empty() && dq.front().second < leftBound) {
        dq.pop_front();  // Remove elements outside window
    }
}

int getMinimum() {
    return dq.front().first;  // Minimum is always at front
}
```

### 3. Frequency Map for Distinct Counting

```cpp
unordered_map<int, int> freq;
int distinctCount = 0;

void addElement(int x) {
    if (freq[x] == 0) distinctCount++;
    freq[x]++;
}

void removeElement(int x) {
    freq[x]--;
    if (freq[x] == 0) distinctCount--;
}
```

### 4. Bit Frequency for OR Operations

```cpp
vector<int> bitCount(32, 0);  // Count of set bits at each position

void addElement(int x) {
    for (int i = 0; i < 32; i++) {
        if (x & (1 << i)) bitCount[i]++;
    }
}

void removeElement(int x) {
    for (int i = 0; i < 32; i++) {
        if (x & (1 << i)) bitCount[i]--;
    }
}

int getCurrentOR() {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (bitCount[i] > 0) result |= (1 << i);
    }
    return result;
}
```

## Problem-Solving Insights

1. **Window Maintenance**: Choose data structure based on required operations
2. **Incremental Updates**: Leverage mathematical properties (XOR self-inverse)
3. **Order Statistics**: Two-set technique for median, monotonic deque for min/max
4. **Frequency Tracking**: Maps for counting, frequency-of-frequency for mode
5. **Bitwise Operations**: Bit frequency arrays for OR/AND operations
6. **Complexity Optimization**: Prefer O(n) solutions over O(n log k) when possible

## Advanced Techniques

### **MEX Calculation**

- Track missing values explicitly with set data structure
- Maintain smallest missing value for O(1) MEX queries
- Use frequency counting to determine element presence

### **Cost Optimization**

- Combine order statistics with sum tracking
- Formula: cost = rightSum - leftSum + median × (leftSize - rightSize)
- Maintain balanced sets with sum information

### **Mode Detection**

- Use frequency map plus frequency-of-frequency tracking
- Maintain maximum frequency and corresponding elements
- Handle ties based on problem requirements
