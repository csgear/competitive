# CSES 11 Sliding Window Problems

## 1076 - Sliding Window Median

- **Description**: Find the median of each sliding window of size k in an array.
- **Key Ideas**: Use two multisets to maintain lower and upper halves. Balance sets so left has at most one more element than right. Median is always the maximum of the left set.

## 1077 - Sliding Window Cost

- **Description**: Calculate the cost to make all elements in each sliding window equal to the median.
- **Key Ideas**: Extend sliding window median with sum tracking. Maintain sums of both halves. Cost = rightSum - leftSum + median \* (leftSize - rightSize).

## 3219 - Sliding Window MEX

- **Description**: Find the MEX (minimum excludant - smallest non-negative integer not in window) for each sliding window.
- **Key Ideas**: Use frequency map and set of missing values. Track which values are missing from current window, MEX is the smallest missing value.

## 3220 - Sliding Window Sum

- **Description**: Given array parameters and window size k, compute XOR of all window sums.
- **Key Ideas**: Use queue to maintain sliding window, track sum by adding new element and removing old element. XOR all window sums together.

## 3221 - Sliding Window Minimum

- **Description**: Find minimum value in each sliding window of size k.
- **Key Ideas**: Use monotonic deque to efficiently track minimum. Store {value, index} pairs, maintain increasing order by removing larger elements from back, remove elements outside window from front.

## 3222 - Sliding Window Distinct Values

- **Description**: Count the number of distinct values in each sliding window of size k.
- **Key Ideas**: Use frequency map to track element counts. Maintain count of distinct elements, increment when new unique element enters, decrement when last occurrence of element leaves.

## 3224 - Sliding Window Mode

- **Description**: Find the mode (most frequent element) in each sliding window of size k.
- **Key Ideas**: Use frequency map and frequency-of-frequency tracking. Maintain maximum frequency and corresponding elements. Update frequency counts as window slides.

## 3405 - Sliding Window OR

- **Description**: Calculate bitwise OR of all elements in each sliding window of size k.
- **Key Ideas**: Track bit frequencies for each position. A bit is set in OR if at least one element in window has that bit set. Use sliding window technique with bit counting.

## 3426 - Sliding Window XOR

- **Description**: Calculate bitwise XOR of all elements in each sliding window of size k.
- **Key Ideas**: Track XOR incrementally - when adding element, XOR it in; when removing element, XOR it out (since XOR is self-inverse). Maintain running XOR of current window.

---

## Algorithm Categories Summary

### **Basic Sliding Window Operations**

- **3220 - Sliding Window Sum**: Simple addition/subtraction tracking
- **3426 - Sliding Window XOR**: XOR with self-inverse property
- **3405 - Sliding Window OR**: Bit frequency counting

### **Order Statistics in Windows**

- **1076 - Sliding Window Median**: Two multisets for median tracking
- **1077 - Sliding Window Cost**: Median + sum tracking for cost calculation
- **3221 - Sliding Window Minimum**: Monotonic deque for efficient min/max

### **Frequency and Counting**

- **3222 - Sliding Window Distinct Values**: Frequency map for distinct counting
- **3224 - Sliding Window Mode**: Frequency-of-frequency for mode tracking
- **3219 - Sliding Window MEX**: Missing value tracking with sets

### **Key Techniques**

- **Monotonic Deque**: Efficient min/max queries (3221)
- **Two Multisets**: Order statistics like median (1076, 1077)
- **Frequency Maps**: Counting distinct elements or modes (3222, 3224)
- **Incremental Updates**: XOR, OR with efficient add/remove (3426, 3405)
- **Missing Value Tracking**: MEX computation with sets (3219)
