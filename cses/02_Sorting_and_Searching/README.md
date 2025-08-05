# CSES 02 Sorting and Searching

This section contains solutions for sorting and searching problems from CSES Problem Set. The problems cover fundamental algorithms including greedy approaches, two pointers, binary search, and advanced data structures.

## Problems Overview

### Basic Sorting & Greedy

| Problem                                                    | Algorithm         | Complexity | Key Concepts                     |
| ---------------------------------------------------------- | ----------------- | ---------- | -------------------------------- |
| [1621 - Distinct Numbers](1621_distinct_numbers.cpp)       | Sorting/Set       | O(n log n) | Duplicate removal                |
| [1084 - Apartments](1084_apartments.cpp)                   | Greedy + Sorting  | O(n log n) | Two pointers, greedy matching    |
| [1090 - Ferris Wheel](1090_ferris_wheel.cpp)               | Greedy + Sorting  | O(n log n) | Two pointers, greedy pairing     |
| [1074 - Stick Length](1074_stick_length.cpp)               | Median            | O(n log n) | Optimization, absolute deviation |
| [1629 - Movie Festival](1629_movie_festival.cpp)           | Greedy Intervals  | O(n log n) | Activity selection               |
| [1630 - Tasks and Deadlines](1630_tasks_and_deadlines.cpp) | Greedy Scheduling | O(n log n) | Deadline scheduling              |
| [1631 - Reading Books](1631_reading_books.cpp)             | Greedy Analysis   | O(n)       | Time optimization                |

### Two Pointers & Binary Search

| Problem                                                    | Algorithm           | Complexity | Key Concepts               |
| ---------------------------------------------------------- | ------------------- | ---------- | -------------------------- |
| [1640 - Sum of Two Values](1640_sum_of_two_values.cpp)     | Two Pointers        | O(n log n) | Target sum, sorting        |
| [1641 - Sum of Three Values](1641_sum_of_three_values.cpp) | Nested Two Pointers | O(n²)      | Multiple target sum        |
| [1642 - Sum of Four Values](1642_sum_of_four_values.cpp)   | Hash Map            | O(n²)      | Quadruple sum optimization |
| [1073 - Towers](1073_towers.cpp)                           | Binary Search       | O(n log n) | LIS variation, multiset    |
| [1620 - Factory Machines](1620_factory_machines.cpp)       | Binary Search       | O(n log T) | Binary search on answer    |
| [1085 - Array Division](1085_array_division.cpp)           | Binary Search       | O(n log S) | Subarray division          |

### Advanced Data Structures

| Problem                                                          | Algorithm         | Complexity | Key Concepts                 |
| ---------------------------------------------------------------- | ----------------- | ---------- | ---------------------------- |
| [1091 - Concert Tickets](1091_concert_tickets.cpp)               | Multiset          | O(n log n) | Dynamic ordered set          |
| [1163 - Traffic Lights](1163_trafic_lights.cpp)                  | Multiset          | O(n log n) | Dynamic gap maintenance      |
| [1164 - Room Allocation](1164_room_allocation.cpp)               | Priority Queue    | O(n log n) | Interval scheduling          |
| [1632 - Movie Festival II](1632_movie_festival_2.cpp)            | Multiset + Greedy | O(n log n) | Multiple resource scheduling |
| [1645 - Nearest Smaller Values](1645_nearest_smaller_values.cpp) | Monotonic Stack   | O(n)       | Stack-based optimization     |

### Subarray Problems

| Problem                                                           | Algorithm            | Complexity | Key Concepts             |
| ----------------------------------------------------------------- | -------------------- | ---------- | ------------------------ |
| [1643 - Maximum Subarray Sum](1643_maximum_subarray_sum.cpp)      | Kadane's Algorithm   | O(n)       | Dynamic programming      |
| [1644 - Maximum Subarray Sum II](1644_maximum_subarray_sum_2.cpp) | Sliding Window Max   | O(n log n) | Constrained optimization |
| [1660 - Subarray Sums I](1660_subarray_sums_1.cpp)                | Two Pointers         | O(n)       | Positive integers        |
| [1661 - Subarray Sums II](1661_subarray_sums_2.cpp)               | Prefix Sum + Map     | O(n log n) | General integers         |
| [1662 - Subarray Divisibility](1662_subarray_divisibility.cpp)    | Prefix Sum + Modular | O(n)       | Modular arithmetic       |
| [2168 - Nested Ranges Check](2168_nested_ranges_check.cpp)        | Sorting + Stack      | O(n log n) | Interval relationships   |
| [2169 - Nested Ranges Count](2169_nested_ranges_count.cpp)        | BIT + Compression    | O(n log n) | Range counting           |

### Mathematical & Special

| Problem                                                                      | Algorithm          | Complexity | Key Concepts             |
| ---------------------------------------------------------------------------- | ------------------ | ---------- | ------------------------ |
| [2183 - Missing Coin Sum](2183_missing_coin_sum.cpp)                         | Greedy Analysis    | O(n log n) | Coin representation      |
| [2216 - Collecting Numbers](2216_collecting_numbers.cpp)                     | Position Analysis  | O(n)       | Sequence ordering        |
| [2217 - Collecting Numbers II](2217_collecting_numbers_2.cpp)                | Dynamic Updates    | O(m)       | Position maintenance     |
| [2162 - Josephus Problem I](2162_josephus_problem_1.cpp)                     | Simulation/Formula | O(n²)/O(n) | Classical problem        |
| [2163 - Josephus Problem II](2163_josephus_problem_2.cpp)                    | Segment Tree       | O(n log n) | Advanced Josephus        |
| [1141 - Playlist](1141_playlist.cpp)                                         | Sliding Window     | O(n)       | Longest unique substring |
| [3420 - Distinct Values Subarrays](3420_distinct_values_subarrays.cpp)       | Sliding Window     | O(n)       | Subarray counting        |
| [3421 - Distinct Values Subsequences](3421_distinct_values_subsequences.cpp) | Combinatorics      | O(n)       | Subsequence counting     |

## Algorithm Categories

### **Greedy Strategies**

- **Interval Problems**: Activity selection, earliest deadline first
- **Matching Problems**: Bipartite matching with constraints
- **Optimization**: Local optimal leads to global optimal

### **Two Pointers Technique**

- **Sorted Arrays**: Target sum problems, range problems
- **Sliding Window**: Fixed/variable size windows
- **Meet in the Middle**: Reduce complexity from O(n³) to O(n²)

### **Binary Search Applications**

- **Search Space**: Binary search on answer
- **Data Structures**: Lower/upper bound operations
- **Optimization**: Finding optimal values in monotonic functions

### **Advanced Data Structures**

- **Balanced Trees**: Multiset, map for dynamic operations
- **Stacks**: Monotonic stack for nearest element problems
- **Binary Indexed Tree**: Range queries with updates

## Key Implementation Patterns

### 1. Two Pointers Template

```cpp
sort(arr, arr + n);
int left = 0, right = n - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) {
        // Found solution
        break;
    } else if (sum < target) {
        left++;
    } else {
        right--;
    }
}
```

### 2. Binary Search on Answer

```cpp
int left = 0, right = MAX_VALUE;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (canAchieve(mid)) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
```

### 3. Monotonic Stack

```cpp
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
    }
    result[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
```

### 4. Sliding Window for Unique Elements

```cpp
unordered_map<int, int> lastPos;
int left = 0, maxLen = 0;
for (int right = 0; right < n; right++) {
    if (lastPos.count(arr[right]) && lastPos[arr[right]] >= left) {
        left = lastPos[arr[right]] + 1;
    }
    lastPos[arr[right]] = right;
    maxLen = max(maxLen, right - left + 1);
}
```

## Problem-Solving Insights

1. **Greedy Choice**: Problems where local optimal leads to global optimal
2. **Sorting Preprocessing**: Many problems become easier after sorting
3. **Binary Search**: When answer space is monotonic
4. **Data Structure Selection**: Choose based on required operations
5. **Subarray Techniques**: Prefix sums, sliding window, two pointers
6. **Coordinate Compression**: Handle large value ranges efficiently
7. **Stack Applications**: Monotonic properties, nearest element problems
