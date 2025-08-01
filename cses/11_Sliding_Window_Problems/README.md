# CSES 11 Sliding Window Problems

## 3220 - Sliding Window Sum

- **Description**: Given array parameters and window size k, compute XOR of all window sums.
- **Key Ideas**: Use queue to maintain sliding window, track sum by adding new element and removing old element. XOR all window sums together.

## 3221 - Sliding Window Minimum

- **Description**: Find minimum value in each sliding window of size k.
- **Key Ideas**: Use monotonic deque to efficiently track minimum. Store {value, index} pairs, maintain increasing order by removing larger elements from back, remove elements outside window from front.
