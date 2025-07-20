## 1628. Meet in the Middle

**Problem:** Given an array of n numbers, in how many ways can you choose a subset of the numbers with sum x?

- [CSES Problem Link](https://cses.fi/problemset/task/1628)

**Constraints:**

- 1 ≤ n ≤ 40
- 1 ≤ x, t_i ≤ 10^9

**Approach:**

- This problem is a classic use case for the "meet in the middle" technique, which is efficient for subset sum problems when n is up to 40.
- The array is split into two halves. All possible subset sums are generated for each half.
- For each subset sum in the second half, the number of ways to pair it with a subset sum from the first half to reach the target sum x is counted using binary search.
- This reduces the time complexity to O(2^{n/2} \* log(2^{n/2})), which is feasible for n up to 40.
